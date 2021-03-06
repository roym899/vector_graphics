// Author: Leonard Bruns (2019)

#ifndef VECTOR_GRAPHICS_ALGORITHMS
#define VECTOR_GRAPHICS_ALGORITHMS

// STL
#include<vector>

// vectorgraphics
#include "Polygon.hpp"

namespace vectorgraphics {
  namespace algorithms {
    std::vector<Point2D> LineSegmentIntersection2D(const LineSegment2D& lineSegment1, const LineSegment2D& lineSegment2);
    std::vector<Polygon2D> PolygonIntersections2D(const std::vector<Polygon2D>& polygons_2d);
    std::vector<Polygon3D> PolygonIntersections3D(const std::vector<Polygon3D>& polygons_3d);
  }
}

#endif
