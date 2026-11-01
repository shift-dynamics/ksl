"""Add a summary table at the top of each section of API documentation.

For every section of an rst page that contains breathe directives
(doxygenfunction, doxygendefine, doxygenunion, ...), a table listing each
documented name and its one-line description is inserted before the first
directive. Names link to their full documentation further down the page.

The descriptions are the @brief lines from the Doxygen XML that breathe
reads, so the tables stay in step with the source code.
"""

import glob
import os
import re
import xml.etree.ElementTree as ET

# breathe directive -> Sphinx C domain role used to link to it
ROLES = {
    "function": "c:func",
    "define": "c:macro",
    "union": "c:union",
    "struct": "c:struct",
    "enum": "c:enum",
    "typedef": "c:type",
}

DIRECTIVE = re.compile(r"^\.\. doxygen(" + "|".join(ROLES) + r")::\s*(\S+)\s*$")
_BRIEFS = {}
UNDERLINE = re.compile(r"^([=\-*^~#\"'+`])\1{2,}\s*$")


def _escape(text):
    return re.sub(r"([\\*`|_])", r"\\\1", text)


def _brief_text(brief):
    """Render a Doxygen <briefdescription> as one line of rst."""
    parts = []

    def walk(node):
        if node.tag == "formula":
            parts.append(" :math:`" + (node.text or "").strip().strip("$").strip() + "` ")
        else:
            if node.text:
                parts.append(_escape(node.text))
            for child in node:
                walk(child)
        if node is not brief and node.tail:
            parts.append(_escape(node.tail))

    walk(brief)
    return re.sub(r"\s+", " ", "".join(parts)).strip()


def _load_briefs(xml_dir):
    briefs = {}

    def add(name, brief):
        if brief is None:
            return
        text = _brief_text(brief)
        if text and not briefs.get(name):
            briefs[name] = text

    # Declarations in headers first: their briefs are the public ones.
    files = sorted(glob.glob(os.path.join(xml_dir, "*_8h.xml"))) + sorted(
        glob.glob(os.path.join(xml_dir, "*.xml")))
    for path in files:
        try:
            root = ET.parse(path).getroot()
        except ET.ParseError:
            continue
        for compound in root.iter("compounddef"):
            if compound.get("kind") in ("struct", "union"):
                add(compound.findtext("compoundname"),
                    compound.find("briefdescription"))
        for member in root.iter("memberdef"):
            add(member.findtext("name"), member.find("briefdescription"))
    # Without a @brief, use the first paragraph of the detailed description.
    for path in files:
        try:
            root = ET.parse(path).getroot()
        except ET.ParseError:
            continue
        for member in root.iter("memberdef"):
            detail = member.find("detaileddescription/para")
            if detail is not None and not briefs.get(member.findtext("name")):
                add(member.findtext("name"), detail)
    return briefs


def _is_heading(lines, i):
    """True if lines[i] is a section title (text followed by an underline)."""
    return (i + 1 < len(lines) and lines[i].strip()
            and not lines[i].startswith(" ")
            and UNDERLINE.match(lines[i + 1])
            and len(lines[i + 1].rstrip()) >= len(lines[i].rstrip()))


def _summary(entries, briefs):
    out = [".. list-table::", "   :class: ksl-summary", "   :widths: 35 65", ""]
    for kind, name in entries:
        out.append(f"   * - :{ROLES[kind]}:`{name}`")
        out.append(f"     - {briefs.get(name, '')}")
    out.append("")
    return out


def _insert_summaries(lines, briefs):
    # Section boundaries: indices of title lines, plus end of file.
    starts = [i for i in range(len(lines)) if _is_heading(lines, i)]
    bounds = starts + [len(lines)]
    inserts = []
    for a, b in zip([0] + bounds, bounds):
        entries, first = [], None
        for i in range(a, b):
            m = DIRECTIVE.match(lines[i])
            if m:
                entries.append((m.group(1), m.group(2)))
                if first is None:
                    first = i
        if len(entries) >= 2:
            inserts.append((first, _summary(entries, briefs)))
    for pos, block in reversed(inserts):
        lines[pos:pos] = block
    return lines


def _source_read(app, docname, source):
    if "doxygen" not in source[0]:
        return
    source[0] = "\n".join(_insert_summaries(source[0].split("\n"), _BRIEFS))


def _builder_inited(app):
    xml_dir = app.config.breathe_projects[app.config.breathe_default_project]
    _BRIEFS.clear()
    _BRIEFS.update(_load_briefs(xml_dir))


def setup(app):
    app.connect("builder-inited", _builder_inited)
    app.connect("source-read", _source_read)
    return {"parallel_read_safe": True, "parallel_write_safe": True}
