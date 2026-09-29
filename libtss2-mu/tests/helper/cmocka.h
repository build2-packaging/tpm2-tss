/* SPDX-License-Identifier: BSD-2-Clause */
/*
 * Minimal drop-in subset of cmocka's public API, backed by plain assert(),
 * so unmodified upstream test/unit source files build without a real
 * cmocka dependency (not published on cppget.org). Covers only what these
 * tests use: no will_return/expect_value/mock() support.
 *
 * Reached both by our own tests/helper/cmocka_all.h (a quoted, same-
 * directory include) and, on toolchains that resolve a symlinked test
 * file's own "../helper/cmocka_all.h" against its upstream/ submodule
 * target instead, by upstream's real test/helper/cmocka_all.h itself
 * (an angle-bracket #include <cmocka.h>, resolved via this directory's
 * own -I search path either way).
 */
#ifndef CMOCKA_H
#define CMOCKA_H

#undef NDEBUG
#include <assert.h>
#include <string.h>

typedef void (*CMUnitTestFunction)(void **state);
typedef int (*CMFixtureFunction)(void **state);

struct CMUnitTest
{
    const char *name;
    CMUnitTestFunction test_func;
    CMFixtureFunction setup_func;
    CMFixtureFunction teardown_func;
    void *initial_state;
};

#define cmocka_unit_test(f) { #f, f, NULL, NULL, NULL }
#define cmocka_unit_test_setup_teardown(f, setup, teardown) \
    { #f, f, setup, teardown, NULL }

#define assert_int_equal(a, b)       assert((a) == (b))
#define assert_null(p)               assert((p) == NULL)
#define assert_non_null(p)           assert((p) != NULL)
#define assert_ptr_equal(a, b)       assert((a) == (b))
#define assert_ptr_not_equal(a, b)   assert((a) != (b))
#define assert_memory_equal(a, b, n) assert(memcmp((a), (b), (n)) == 0)
#define assert_string_equal(a, b)    assert(strcmp((a), (b)) == 0)

static inline int
cmocka_run_group_tests_(const struct CMUnitTest *tests, size_t n)
{
    size_t i;

    for (i = 0; i < n; i++) {
        void *state = tests[i].initial_state;

        if (tests[i].setup_func != NULL)
            assert(tests[i].setup_func(&state) == 0);

        tests[i].test_func(&state);

        if (tests[i].teardown_func != NULL)
            assert(tests[i].teardown_func(&state) == 0);
    }

    return 0;
}

#define cmocka_run_group_tests(tests, group_setup, group_teardown) \
    cmocka_run_group_tests_((tests), sizeof(tests) / sizeof((tests)[0]))

#endif /* CMOCKA_H */
