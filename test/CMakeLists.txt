cmake_minimum_required(VERSION 3.14)

project(dotenvTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(dotenv REQUIRED)
  enable_testing()
endif()

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

add_executable(dotenv_test source/dotenv_test.cpp)
target_link_libraries(
    dotenv_test PRIVATE
    dotenv::dotenv
    Catch2::Catch2WithMain
)
target_compile_features(dotenv_test PRIVATE cxx_std_17)

catch_discover_tests(dotenv_test)

# ---- End-of-file commands ----

add_folders(Test)
