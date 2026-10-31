# generated headers, included as "ksl/<name>.h"
git = find_program('git', required: false)
git_commit = 'unknown'
git_branch = 'unknown'
if git.found()
  r = run_command(git, 'log', '-1', '--format=%h', check: false)
  if r.returncode() == 0
    git_commit = r.stdout().strip()
  endif
  r = run_command(git, 'rev-parse', '--abbrev-ref', 'HEAD', check: false)
  if r.returncode() == 0
    git_branch = r.stdout().strip()
  endif
endif

version = meson.project_version().split('.')
ksl_version_h = configure_file(
  input: 'version.h.in',
  output: 'version.h',
  configuration: {
    'ksl_VERSION_MAJOR': version[0],
    'ksl_VERSION_MINOR': version[1],
    'ksl_VERSION_PATCH': version[2],
    'KSL_GIT_COMMIT': git_commit,
    'KSL_GIT_BRANCH': git_branch,
  },
)
