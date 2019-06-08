// Author: Leonard Bruns (2019)

#ifndef VECTOR_GRAPHICS_POINT
#define VECTOR_GRAPHICS_POINT

#include "Primitive.hpp"

namespace vectorgraphics {
  ///////////////////////////////////////////////////////////////////////////////
  /// \brief A point in 2D space.
  class Point2D : public Primitive {
    double x, y;
  };

  ///////////////////////////////////////////////////////////////////////////////
  /// \brief A point in 3D space.
  class Point3D : public Primitive {
    double x, y, z;
  };
}


#endif
