// Author: Leonard Bruns (2019)
#include "vector_graphics/Polygon.hpp"

namespace vectorgraphics {
  Polygon2D::Polygon2D(std::vector<double> coordinates) {
    size_t index=0;
    while(index+1 < coordinates.size()) {
      point_ptrs_.push_back(std::make_shared<Point2D>(coordinates[index], coordinates[index+1]));
      index += 2;
    }

    index = 1;
    while(index < point_ptrs_.size()) {
      line_segment_ptrs_.push_back(std::make_shared<LineSegment2D>(point_ptrs_[index-1], point_ptrs_[index]));
      index += 1;
    }
    line_segment_ptrs_.push_back(std::make_shared<LineSegment2D>(point_ptrs_[index-1], point_ptrs_[0]));
  }

  Polygon2D::Polygon2D(std::vector<Point2DPtr> point_ptrs) :
    point_ptrs_(point_ptrs) {
    size_t index=1;
    while(index < point_ptrs_.size()) {
      line_segment_ptrs_.push_back(std::make_shared<LineSegment2D>(point_ptrs_[index-1], point_ptrs_[index]));
      index += 1;
    }
    line_segment_ptrs_.push_back(std::make_shared<LineSegment2D>(point_ptrs_[index-1], point_ptrs_[0]));
  }

  void Polygon2D::addStyleToLineSegments(StylePtr style_ptr) {
    for(const auto& line_segment_ptr : line_segment_ptrs_) {
      line_segment_ptr->addStyle(style_ptr);
    }
  }

  void Polygon2D::addStyleToPoints(StylePtr style_ptr) {
    for(const auto& point_ptr : point_ptrs_) {
      point_ptr->addStyle(style_ptr);
    }
  }

  Polygon3D::Polygon3D(std::vector<double> coordinates) {
    size_t index=0;
    while(index+2 < coordinates.size()) {
      point_ptrs_.push_back(std::make_shared<Point3D>(coordinates[index], coordinates[index+1], coordinates[index+2]));
      index += 3;
    }

    index = 1;
    while(index < point_ptrs_.size()) {
      line_segment_ptrs_.push_back(std::make_shared<LineSegment3D>(point_ptrs_[index-1], point_ptrs_[index]));
      index += 1;
    }
    line_segment_ptrs_.push_back(std::make_shared<LineSegment3D>(point_ptrs_[index-1], point_ptrs_[0]));
  }

  Polygon3D::Polygon3D(std::vector<Point3DPtr> point_ptrs) :
    point_ptrs_(point_ptrs) {
    size_t index=1;
    while(index < point_ptrs_.size()) {
      line_segment_ptrs_.push_back(std::make_shared<LineSegment3D>(point_ptrs_[index-1], point_ptrs_[index]));
      index += 1;
    }
    line_segment_ptrs_.push_back(std::make_shared<LineSegment3D>(point_ptrs_[index-1], point_ptrs_[0]));
  }
}