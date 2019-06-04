# Defining the library
add_library(vector_graphics_lib STATIC Point2D.cpp )
target_include_directories(vector_graphics_lib PUBLIC include/vector_graphics)
target_compile_features(vector_graphics_lib PUBLIC cxx_std_14)