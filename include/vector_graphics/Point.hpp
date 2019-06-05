// Author: Leonard Bruns (2019)

#ifndef VECTOR_GRAPHICS_POINT
#define VECTOR_GRAPHICS_POINT

namespace vectorgraphics {
  ///////////////////////////////////////////////////////////////////////////////
  /// \brief A point in 2D space.
  struct Point2D {
    double x, y;
  };

  ///////////////////////////////////////////////////////////////////////////////
  /// \brief A point in 3D space.
  struct Point3D {
    double x, y, z;
  };
}


#endif
