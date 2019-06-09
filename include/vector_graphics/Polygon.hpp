// Author: Leonard Bruns (2019)

#ifndef VECTOR_GRAPHICS_POLYGON
#define VECTOR_GRAPHICS_POLYGON

// STL
#include <vector>

// vectorgraphics
#include "LineSegment.hpp"
#include "Primitive.hpp"
#include "Style.hpp"

namespace vectorgraphics {

  class Polygon2D : public Primitive {
  public:
    Polygon2D(std::vector<double> coordinates);
    Polygon2D(std::vector<Point2DPtr> point_ptrs);
    void addStyleToLineSegments(StylePtr style_ptr);
    void addStyleToPoints(StylePtr style_ptr);
    std::vector<LineSegment2DPtr> line_segment_ptrs_;
    std::vector<Point2DPtr> point_ptrs_;
  };


  class Polygon3D : public Primitive {
  public:
    Polygon3D(std::vector<double> coordinates);
    Polygon3D(std::vector<Point3DPtr> point_ptrs);
    void addStyleToLineSegments(StylePtr style_ptr);
    void addStyleToPoints(StylePtr style_ptr);
    std::vector<LineSegment3DPtr> line_segment_ptrs_;
    std::vector<Point3DPtr> point_ptrs_;
  };
}

#endif
