// Author: Leonard Bruns (2019)

// #include "Point3D.hpp"
// #include "Polygon.hpp"
// #include "GeometryAlgorithms.hpp"

// vector_graphics
#include "vector_graphics/TikzPlotter.hpp"
#include "vector_graphics/Point.hpp"
#include "vector_graphics/Style.hpp"


// STD
#include <filesystem>
#include <memory>

namespace vg=vectorgraphics;

int main() {
  /// This demo showcases creating a pdf from from code and different options to style 2D primitives.

  // First create the primitives
  // three points with different colors
  vg::Point2D p1(0,0), p2(2,0), p3(0,2);
  p1.style_ptrs.push_back(std::make_shared<vg::Style>(vg::StyleMap{{"draw","red"},{"fill","red"},{"radius","1pt"}}));
  p2.style_ptrs.push_back(std::make_shared<vg::Style>(vg::StyleMap{{"draw","blue"},{"fill","blue"},{"radius","1pt"}}));
  p3.style_ptrs.push_back(std::make_shared<vg::Style>(vg::StyleMap{{"draw","green"},{"fill","green"},{"radius","1pt"}}));

  // a dashed line segment
  vg::LineSegment2D line1(0.25,0.25,0.75,0.75);
  line1.style_ptrs.push_back(std::make_shared<vg::Style>(vg::StyleMap{{"draw","red"},{"*line_path","dashed"}}));

  // Create the file
  vg::TikzPlotter tp;
  tp.addPoint(p1);
  tp.addPoint(p2);
  tp.addPoint(p3);
  tp.addLineSegment(line1);
  tp.makePDF("./demos_output", "demo_pdf");
  return 0; 
}
