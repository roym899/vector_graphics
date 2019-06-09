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
  struct LineSegment2D : public Primitive {
    Point2DPtr start_ptr_, end_ptr_;
  };
  typedef std::shared_ptr<LineSegment2D> LineSegment2DPtr;

  ///////////////////////////////////////////////////////////////////////////////
  /// \brief A line segment in 2D. An arbitray line is made up of multiple such 
  /// line segments.
  struct LineSegment3D : public Primitive {
    Point3DPtr start_ptr_, end_ptr_;
  };
  typedef std::shared_ptr<LineSegment2D> LineSegment3DPtr;
}

#endif
