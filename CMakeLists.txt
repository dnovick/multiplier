cmake_minimum_required(VERSION 3.22)
project(KeyGenerationUtility)

set(CMAKE_CXX_STANDARD 20)


set(CMAKE_EXPORT_COMPILE_COMMANDS True)




include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(PROJECT_EXE multiplier)

add_executable(${PROJECT_EXE}
    main.cpp
    multiplier.h
    multiplier_tests.h
    
    
    )


enable_testing()

target_link_libraries(${PROJECT_EXE}
    GTest::gtest_main

    )


include(GoogleTest)

gtest_discover_tests(${PROJECT_EXE})