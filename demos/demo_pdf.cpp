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
  p1.addStyle(std::make_shared<vg::Style>(vg::StyleMap{{"draw","red"},{"fill","red"},{"radius","1pt"}}));
  p2.addStyle(std::make_shared<vg::Style>(vg::StyleMap{{"draw","blue"},{"fill","blue"},{"radius","1pt"}}));
  p3.addStyle(std::make_shared<vg::Style>(vg::StyleMap{{"draw","green"},{"fill","green"},{"radius","1pt"}}));

  // a dashed line segment
  vg::LineSegment2D line1(0.25,0.25,0.75,0.75);
  line1.addStyle(std::make_shared<vg::Style>(vg::StyleMap{{"draw","red"},{"*line_path","dashed"}}));

  // a filled rectangle
  vg::Polygon2D poly1({-1.,-1.,3.,-1.,3.,3.,-1.,3.});
  poly1.addStyle(std::make_shared<vg::Style>(vg::StyleMap{{"draw","black"},{"fill","black"},{"fill opacity","0.3"},{"line width", "2pt"}}));
  poly1.addStyleToLineSegments(std::make_shared<vg::Style>(vg::StyleMap{{"draw", "red"},{"*line_path", "dashed"}}));
  poly1.addStyleToPoints(std::make_shared<vg::Style>(vg::StyleMap{{"draw", "green"},{"fill", "green"},{"radius", "0.1"}}));

  // Create the file
  vg::TikzPlotter tp;
  tp.addPolygon(poly1);
  tp.addPoint(p1);
  tp.addPoint(p2);
  tp.addPoint(p3);
  tp.addLineSegment(line1);
  tp.makePDF("./demos_output", "demo_pdf");
  return 0; 
}
