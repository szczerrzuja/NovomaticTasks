# CMakeList.txt : CMake project for NovomaticTask3, include source and define
# project specific logic here.
#

# Add source to this project's executable.
project("NovomaticTask3")
add_executable (NovomaticTask3 "NovomaticTask3.cpp" "NovomaticTask3.h" "Triangle.h" "Triangle.cpp" "UserInterface.cpp" "UserInterface.h" "TextBox.h" "TextBox.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NovomaticTask3 PROPERTY CXX_STANDARD 20)
endif()

set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SFML/include")
set(SFML_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/SFML/lib")
set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML/lib/cmake/SFML")

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)


include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIBRARY_DIR})
find_library(SFML_GRAPHICS sfml-graphics-d-2 ${SFML_DIR}/directory)




target_link_libraries(NovomaticTask3 sfml-system sfml-window sfml-graphics sfml-network sfml-audio)


# TODO: Add tests and install targets if needed.
