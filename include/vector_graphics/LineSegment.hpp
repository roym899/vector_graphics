// Author: Leonard Bruns (2019)

#ifndef VECTOR_GRAPHICS_LINESEGMENT
#define VECTOR_GRAPHICS_LINESEGMENT

// STL
#include <memory>

// vector_graphics
#include "Point.hpp"
#include "Primitive.hpp"

namespace vectorgraphics {
  ///////////////////////////////////////////////////////////////////////////////
  /// \brief A line segment in 2D. An arbitray line is made up of multiple such 
  /// line segments.
  class LineSegment2D : public Primitive {
  public:
    LineSegment2D(Point2DPtr start_ptr, Point2DPtr end_ptr);
    LineSegment2D(double start_x, double start_y, double end_x, double end_y);
    Point2DPtr start_ptr_, end_ptr_;
  };
  typedef std::shared_ptr<LineSegment2D> LineSegment2DPtr;

  ///////////////////////////////////////////////////////////////////////////////
  /// \brief A line segment in 2D. An arbitray line is made up of multiple such 
  /// line segments.
  class LineSegment3D : public Primitive {
  public:
    LineSegment3D(Point3DPtr start_ptr, Point3DPtr end_ptr);
    LineSegment3D(double start_x, double start_y, double start_z, double end_x, double end_y, double end_z);
    Point3DPtr start_ptr_, end_ptr_;
  };
  typedef std::shared_ptr<LineSegment2D> LineSegment3DPtr;
}

#endif
