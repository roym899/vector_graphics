// Author: Leonard Bruns (2019)

#ifndef VECTOR_GRAPHICS_POLYGON
#define VECTOR_GRAPHICS_POLYGON

// STL
#include <vector>

// vectorgraphics
#include "LineSegment.hpp"

namespace vectorgraphics {

  class Polygon2D {
  public:
    void add_point();
    double area() const;
  private:
    std::vector<LineSegment2D> lineSegments;
  };


  class Polygon3D {
  public:
    void add_point();
    double area() const;
  private:
    std::vector<LineSegment3D> lineSegments;
  };
}

#endif
