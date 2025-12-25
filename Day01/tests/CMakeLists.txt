add_executable(tests
    test_main.cpp
    ../functions.cpp
)

target_link_libraries(tests
    gtest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
