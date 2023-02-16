cmake_minimum_required(VERSION 3.16.3)
project(Demo VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()


# Apple specific settings
#------------------------------------------------------------

if(APPLE)
  set(CMAKE_CXX_STANDARD 14)
  set_target_properties(PROPERTIES CXX_STANDARD 98 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)
  message("Building for Apple")
else()
endif(APPLE)

# Client sources and includes
#------------------------------------------------------------

set(SOURCES
  src/main.cpp
  src/game.cpp
  src/systems/miner.cpp
  src/systems/background.cpp
)

include_directories(. build/_deps/eecsge-src)

# BOOST
#------------------------------------------------------------
# find_package(Boost 1.45.0 COMPONENTS filesystem) 

# if(Boost_FOUND)
#     include_directories(${Boost_INCLUDE_DIRS}) 
#     add_executable(progname file1.cxx file2.cxx) 
#     target_link_libraries(progname ${Boost_LIBRARIES})
# endif()

# SFML
#------------------------------------------------------------



include(FetchContent)


FetchContent_Declare(eecsge
    GIT_REPOSITORY https://github.com/Shorssaud/EECSGE
    GIT_TAG main
)
FetchContent_MakeAvailable(eecsge)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.x)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(GTEST
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG v1.13.x)
FetchContent_MakeAvailable(GTEST)

add_executable(Demo ${SOURCES})

target_link_libraries(Demo sfml-audio sfml-graphics sfml-system sfml-window eecsge)


# Testing
#------------------------------------------------------------

set(SOURCES_TEST
  ${PROJECT_SOURCE_DIR}/ecs/systems/player.cpp
  ${PROJECT_SOURCE_DIR}/tests/test_InputEngine.cpp
)

set(INCLUDE_TEST
  ${gtest_SOURCE_DIR}/include
  ${gtest_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/include
)

IF(test AND test STREQUAL "on")
  message("Testing enabled")

  file(GLOB TEST_SRC_FILES ${SOURCES_TEST})

  enable_testing()
  
  include_directories(${INCLUDE_TEST})

  add_executable(runUnitTests ${TEST_SRC_FILES})
  
  target_link_libraries(runUnitTests gtest gtest_main sfml-audio sfml-graphics sfml-system sfml-window -leecsge)

  add_test(UnitTests runUnitTests)

ENDIF()
#------------------------------------------------------------

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
