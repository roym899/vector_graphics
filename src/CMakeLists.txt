# Defining the library
add_library(vector_graphics_lib STATIC Point.cpp TikzPlotter.cpp Algorithms.cpp LineSegment.cpp Polygon.cpp)
target_include_directories(vector_graphics_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_features(vector_graphics_lib PUBLIC cxx_std_17)
target_link_libraries(vector_graphics_lib PUBLIC stdc++fs)