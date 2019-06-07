// Author: Leonard Bruns (2019)

// #include "Point3D.hpp"
// #include "Polygon.hpp"
// #include "GeometryAlgorithms.hpp"

#include "vector_graphics/TikzPlotter.hpp"

int main() {
  // std::vector<Polygon2D> polygons_2d;
  // polygons_2d.emplace_back();
  // polygons_2d.emplace_back();

  // polygons_2d[0].add_point(0,0);
  // polygons_2d[0].add_point(1,0);
  // polygons_2d[0].add_point(1,1);

  // polygons_2d[1].add_point(0.5,0.5);
  // polygons_2d[1].add_point(1.5,0.5);
  // polygons_2d[1].add_point(1.5,1);

  // std::vector<Polygon2D> split_polygons_2d = GeometryAlgorithms::PolygonIntersections2D();

  vectorgraphics::TikzPlotter tp;
  // std::cout << "test" << std::endl;
  tp.makePDF("test.tex");
  return 0;
}
