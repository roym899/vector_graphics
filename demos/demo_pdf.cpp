// Author: Leonard Bruns (2019)

// #include "Point3D.hpp"
// #include "Polygon.hpp"
// #include "GeometryAlgorithms.hpp"

#include "vector_graphics/TikzPlotter.hpp"
#include <filesystem>

int main() {
  /// This demo showcases creating a pdf from from code and different options to style 2D primitives.

  // First create the primitives

  // Create the file
  vectorgraphics::TikzPlotter tp;
  tp.makePDF("./demos_output", "demo_pdf");
  return 0;
}
