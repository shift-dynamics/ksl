.. index:: pair: struct; ksl_print_options_t
.. _doxid-structksl__print__options__t:
.. _cid-ksl_print_options_t:

struct ksl_print_options_t
==========================

.. toctree::
	:hidden:

.. code-block:: cpp
	:class: overview-code-block

	#include <print.h>


Overview
~~~~~~~~

print formatting options :ref:`More...<details-doxid-structksl__print__options__t>`

.. ref-code-block:: cpp
	:class: overview-code-block

	// fields

	char :ref:`delimiter<doxid-structksl__print__options__t_1aadc27441ec71353d6538b4c0d84c00e1>` [100]
	char :ref:`real_fmt<doxid-structksl__print__options__t_1af2141436a6ae5ce78ac5780e20470373>` [100]
	char :ref:`int_fmt<doxid-structksl__print__options__t_1a9b93af3d2506a3a3b8b18007021ae287>` [100]
	char :ref:`true_fmt<doxid-structksl__print__options__t_1afc87f82d22da9dbdaeda15602ff65f87>` [100]
	char :ref:`false_fmt<doxid-structksl__print__options__t_1a673fbf147cda30efe2dbdc7e1a4cedbe>` [100]
	char :ref:`inner_left_bracket<doxid-structksl__print__options__t_1a4dfeb1f7a3fca786a773e52506d1bd81>` [100]
	char :ref:`inner_right_bracket<doxid-structksl__print__options__t_1a6e243ceb91568d86e9f8a349aae99db0>` [100]
	char :ref:`outer_left_bracket<doxid-structksl__print__options__t_1aea5fe6c8258734b8635959b53d1d2144>` [100]
	char :ref:`outer_right_bracket<doxid-structksl__print__options__t_1a8098c3eb77b9d270a40af0b0802ade49>` [100]
	ksl_print_breakBetweenLines_enum_t :ref:`line_breaks_in_matrices<doxid-structksl__print__options__t_1ab59b3a3c7b73272e36906c61db9e3fb2>`
	ksl_matrix_enum_t :ref:`print_row_column_major<doxid-structksl__print__options__t_1aa1f961242b243097c2a1466cf8d00060>`

.. _details-doxid-structksl__print__options__t:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~

print formatting options

Fields
------

.. _doxid-structksl__print__options__t_1aadc27441ec71353d6538b4c0d84c00e1:
.. _cid-ksl_print_options_t::delimiter:
.. ref-code-block:: cpp
	:class: title-code-block

	char delimiter [100]

default delimiter, default: ", "

.. _doxid-structksl__print__options__t_1af2141436a6ae5ce78ac5780e20470373:
.. _cid-ksl_print_options_t::real_fmt:
.. ref-code-block:: cpp
	:class: title-code-block

	char real_fmt [100]

formatting for doubles and floats, default: "%0.6g"

.. _doxid-structksl__print__options__t_1a9b93af3d2506a3a3b8b18007021ae287:
.. _cid-ksl_print_options_t::int_fmt:
.. ref-code-block:: cpp
	:class: title-code-block

	char int_fmt [100]

formatting for ints: default: "%d"

.. _doxid-structksl__print__options__t_1afc87f82d22da9dbdaeda15602ff65f87:
.. _cid-ksl_print_options_t::true_fmt:
.. ref-code-block:: cpp
	:class: title-code-block

	char true_fmt [100]

formatting for display of true boolean, default: "true"

.. _doxid-structksl__print__options__t_1a673fbf147cda30efe2dbdc7e1a4cedbe:
.. _cid-ksl_print_options_t::false_fmt:
.. ref-code-block:: cpp
	:class: title-code-block

	char false_fmt [100]

formatting for display of false boolean, default: "false"

.. _doxid-structksl__print__options__t_1a4dfeb1f7a3fca786a773e52506d1bd81:
.. _cid-ksl_print_options_t::inner_left_bracket:
.. ref-code-block:: cpp
	:class: title-code-block

	char inner_left_bracket [100]

default: "["

.. _doxid-structksl__print__options__t_1a6e243ceb91568d86e9f8a349aae99db0:
.. _cid-ksl_print_options_t::inner_right_bracket:
.. ref-code-block:: cpp
	:class: title-code-block

	char inner_right_bracket [100]

default: "]"

.. _doxid-structksl__print__options__t_1aea5fe6c8258734b8635959b53d1d2144:
.. _cid-ksl_print_options_t::outer_left_bracket:
.. ref-code-block:: cpp
	:class: title-code-block

	char outer_left_bracket [100]

default: "["

.. _doxid-structksl__print__options__t_1a8098c3eb77b9d270a40af0b0802ade49:
.. _cid-ksl_print_options_t::outer_right_bracket:
.. ref-code-block:: cpp
	:class: title-code-block

	char outer_right_bracket [100]

default: "]"

.. _doxid-structksl__print__options__t_1ab59b3a3c7b73272e36906c61db9e3fb2:
.. _cid-ksl_print_options_t::line_breaks_in_matrices:
.. ref-code-block:: cpp
	:class: title-code-block

	ksl_print_breakBetweenLines_enum_t line_breaks_in_matrices

default: KSL_BREAK_BETWEEN_LINES

.. _doxid-structksl__print__options__t_1aa1f961242b243097c2a1466cf8d00060:
.. _cid-ksl_print_options_t::print_row_column_major:
.. ref-code-block:: cpp
	:class: title-code-block

	ksl_matrix_enum_t print_row_column_major

default: KSL_ROW_MAJOR

