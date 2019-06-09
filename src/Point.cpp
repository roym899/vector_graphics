// Author: Leonard Bruns (2019)
#include "vector_graphics/Point.hpp"

namespace vectorgraphics {
  std::ostream& operator<<(std::ostream &out, const Point2D &point_2d) {
    out << "(" << point_2d.x_ << ", " << point_2d.y_ << ") ";
    return out;
  }
}