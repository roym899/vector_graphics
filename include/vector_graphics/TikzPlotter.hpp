// Author: Leonard Bruns (2019)

#ifndef VECTOR_GRAPHICS_TIKZPLOTTER
#define VECTOR_GRAPHICS_TIKZPLOTTER

// STL
#include <vector>
#include <string>
#include <sstream>
#include <filesystem>

#include "Polygon.hpp"

namespace vectorgraphics {

  class TikzPlotter {
  public:
    void addPolygon(const Polygon2D& polygon_2d);
    void addLineSegment(const LineSegment2D &line_segment_2d);
    void addPoint(const Point2D &point_2d);
    void makePDF(std::filesystem::path path, std::string name);
  private:
    bool createTexFile(std::filesystem::path tex_path) const;
    bool compileTexFile(std::filesystem::path path, std::string name) const;
    static bool cleanup(std::filesystem::path path, std::string name);
    std::stringstream content;
  };

}

#endif
