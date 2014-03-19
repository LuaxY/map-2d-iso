file(GLOB sources *.cpp)
file(GLOB headers *.hpp)

#include_directories(${SFML_INCLUDE_DIR})
add_executable(map-2d-iso ${sources} ${headers})
target_link_libraries(map-2d-iso ${SFML_LIBRARIES})