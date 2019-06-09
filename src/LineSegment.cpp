// Author: Leonard Bruns (2019)
#include "vector_graphics/LineSegment.hpp"

namespace vectorgraphics {
  LineSegment2D::LineSegment2D(Point2DPtr start_ptr, Point2DPtr end_ptr) :
    start_ptr_(start_ptr), end_ptr_(end_ptr) {
  }

  LineSegment2D::LineSegment2D(double start_x, double start_y, double end_x, double end_y) : 
    start_ptr_(std::make_shared<Point2D>(start_x, start_y)), 
    end_ptr_(std::make_shared<Point2D>(end_x, end_y)) {
  }

  LineSegment3D::LineSegment3D(Point3DPtr start_ptr, Point3DPtr end_ptr) :
    start_ptr_(start_ptr), end_ptr_(end_ptr) {
  }

  LineSegment3D::LineSegment3D(double start_x, double start_y, double start_z, double end_x, double end_y, double end_z) : 
    start_ptr_(std::make_shared<Point3D>(start_x, start_y, start_z)), 
    end_ptr_(std::make_shared<Point3D>(end_x, end_y, end_z)) {
  }
}