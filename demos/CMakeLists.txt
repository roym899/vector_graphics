# Defining the example app
add_executable(demo_pdf demo_pdf.cpp)
target_link_libraries(demo_pdf PUBLIC vector_graphics_lib)
target_compile_features(demo_pdf PUBLIC cxx_std_11)