// Author: Leonard Bruns (2019)

#ifndef POLYGON3D
#define POLYGON3D

#include <vector>

class Polygon3D {
public:
  void add_point();
  double area() const;
private:
  std::vector<LineSegment3D> lineSegments;
}

#endif
