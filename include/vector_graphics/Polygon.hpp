// Author: Leonard Bruns (2019)

#ifndef VECTOR_GRAPHICS_POLYGON
#define VECTOR_GRAPHICS_POLYGON

// STL
#include <vector>

// vectorgraphics
#include "LineSegment.hpp"
#include "Primitive.hpp"

namespace vectorgraphics {

  class Polygon2D : public Primitive {
  public:
    void add_point();
    double area() const;
    std::vector<LineSegment2DPtr>& getLineSegmentPtrs() { return line_segment_ptrs_; };
  private:
    std::vector<LineSegment2DPtr> line_segment_ptrs_;
  };


  class Polygon3D : public Primitive {
  public:
    void add_point();
    double area() const;
    std::vector<LineSegment3DPtr>& getLineSegmentPtrs() { return line_segment_ptrs_; };
  private:
    std::vector<LineSegment3DPtr> line_segment_ptrs_;
  };
}

#endif
