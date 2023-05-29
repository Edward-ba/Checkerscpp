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

include_directories (/usr/include)
include_directories (/usr/local/include)

link_directories (/usr/lib)
link_directories (/usr/local/lib)

add_executable(checkers
  checkers/main.cpp
  checkers/src/piece.cpp
)

add_executable(checkers1
    checkers1/main.cpp
    checkers1/src/piece.cpp
    checkers1/src/coordinate.cpp
    checkers1/src/pawn.cpp
    checkers1/src/king.cpp
    checkers1/src/board.cpp
)
