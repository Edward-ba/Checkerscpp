cmake_minimum_required (VERSION 3.1.0)
project (cpp1)

# Set Configuration specific DEFINES
IF ( CMAKE_BUILD_TYPE STREQUAL "Debug" ) 
  add_definitions ( "-DUSE_PERFORMANCE_DATA")
  add_definitions ( "-DDEBUG " )
  add_definitions ( "-D_DEBUG " )
  add_definitions ( "-std=c++20")
  add_definitions ( "-rdynamic ")
  add_definitions ( "-g ")

  add_definitions ( "-Wno-deprecated ")
  add_definitions ( "-Wno-unknown-pragmas ")

ELSE()
  add_definitions ( "-Wall ")
  add_definitions ( "-DNDEBUG " )
  add_definitions ( "-DUSE_PERFORMANCE_DATA")
  add_definitions ( "-O3 ")
  add_definitions ( "-std=c++20")
  add_definitions ( "-march=native ")
  add_definitions ( "-mtune=native ")
  add_definitions ( "-Wno-deprecated ")
  add_definitions ( "-Wno-unknown-pragmas ")
  add_definitions ( "-rdynamic ")
  add_definitions ( "-g ")
ENDIF()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories (/usr/include)
include_directories (/usr/local/include)

link_directories (/usr/lib)
link_directories (/usr/local/lib)

add_library(checkerslib SHARED
  checkerslib/src/piece.cpp
  checkerslib/src/coordinate.cpp
  checkerslib/src/pawn.cpp
  checkerslib/src/king.cpp
  checkerslib/src/board.cpp
)

add_executable(checkers
    checkers/main.cpp
)
target_link_libraries(checkers checkerslib
)

enable_testing()

add_executable(checkers_test
  tests/main.cpp
)
target_link_libraries(checkers_test
  GTest::gtest_main
  checkerslib
)

include(GoogleTest)
gtest_discover_tests(checkers_test)
