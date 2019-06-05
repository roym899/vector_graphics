// Author: Leonard Bruns (2019)

#ifndef VECTOR_GRAPHICS_LINESEGMENT
#define VECTOR_GRAPHICS_LINESEGMENT

#include "Point.hpp"

namespace vectorgraphics {
  ///////////////////////////////////////////////////////////////////////////////
  /// \brief A line segment in 2D. An arbitray line is made up of multiple such 
  /// line segments.
  struct LineSegment2D {
    Point2D start, end;
  };

  ///////////////////////////////////////////////////////////////////////////////
  /// \brief A line segment in 2D. An arbitray line is made up of multiple such 
  /// line segments.
  struct LineSegment3D {
    Point3D start, end;
  };
}

#endif
