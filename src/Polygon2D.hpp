// Author: Leonard Bruns (2019)

#ifndef POLYGON2D
#define POLYGON2D

#include <vector>

class Polygon2D {
public:
  void add_point();
  double area() const;
private:
  std::vector<LineSegment2D> lineSegments;
}

#endif
