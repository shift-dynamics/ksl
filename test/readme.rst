Adding unit tests
=================

Each unit test is enclosed within a ``START_TEST``- ``END_TEST`` block.

.. code::

    START_TEST(test_axis_create) {
      ksl_vec3i_t axis = ksl_axis_getVector(KSL_AXIS_XYZ);
      ck_assert(axis.x == 0);
      ck_assert(axis.y == 1);
      ck_assert(axis.z == 2);
    }
    END_TEST


The primary checking mechanisms provided by the Check library are the ``ck_assert`` or ``ck_assert_msg`` functions. However there are a number of other macros described on the Check website at: https://libcheck.github.io/check/doc/check_html/check_4.html#Convenience-Test-Functions that may be useful for more complicated tests.

Once you have added a new unit test above, add it to the list of tests in a test suite as:

.. code::

    Suite* axis_suite(void) {
      Suite* s = suite_create("axis");
      TCase* tc_core = tcase_create("core");
      tcase_add_test(tc_core, test_axis_create); /*< test is added here! */
      suite_add_tcase(s, tc_core);
      return s;
    }
