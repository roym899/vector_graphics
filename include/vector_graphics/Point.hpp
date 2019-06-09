// Author: Leonard Bruns (2019)

#ifndef VECTOR_GRAPHICS_POINT
#define VECTOR_GRAPHICS_POINT

// STL
#include <memory>

// vector_graphics
#include "Primitive.hpp"

namespace vectorgraphics {
  ///////////////////////////////////////////////////////////////////////////////
  /// \brief A point in 2D space.
  class Point2D : public Primitive {
  public:
    double x, y;
  };
  typedef std::shared_ptr<Point2D> Point2DPtr;

  ///////////////////////////////////////////////////////////////////////////////
  /// \brief A point in 3D space.
  class Point3D : public Primitive {
  public:
    double x, y, z;
  };
  typedef std::shared_ptr<Point3D> Point3DPtr;
}


#endif
