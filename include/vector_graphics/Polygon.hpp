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
    std::vector<std::shared_ptr<LineSegment2D>>& getLineSegmentPtrs() { return lineSegmentPtrs; };
  private:
    std::vector<std::shared_ptr<LineSegment2D>> lineSegmentPtrs;
  };


  class Polygon3D : public Primitive {
  public:
    void add_point();
    double area() const;
    std::vector<std::shared_ptr<LineSegment3D>>& getLineSegmentPtrs() { return lineSegmentPtrs; };
  private:
    std::vector<std::shared_ptr<LineSegment3D>> lineSegmentPtrs;
  };
}

#endif
