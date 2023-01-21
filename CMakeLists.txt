cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    dotenv
    VERSION 0.1.0
    DESCRIPTION "A single header library for .env loading"
    HOMEPAGE_URL "https://github.com/alexriegler/dotenv"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(dotenv_dotenv INTERFACE)
add_library(dotenv::dotenv ALIAS dotenv_dotenv)

set_property(
    TARGET dotenv_dotenv PROPERTY
    EXPORT_NAME dotenv
)

target_include_directories(
    dotenv_dotenv ${warning_guard}
    INTERFACE
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_compile_features(dotenv_dotenv INTERFACE cxx_std_17)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT dotenv_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of dotenv"
  )
endif()

include(cmake/dev-mode.cmake)
