// Author: Leonard Bruns (2019)

#ifndef VECTOR_GRAPHICS_TIKZPLOTTER
#define VECTOR_GRAPHICS_TIKZPLOTTER

// STL
#include <vector>
#include <sstream>
#include <filesystem>
#include <boost/format.hpp>

#include "Polygon.hpp"

namespace vectorgraphics {

  class TikzPlotter {
  public:
    void addPolygon(const Polygon2D& polygon_2d);
    void makePDF(std::filesystem::path path);
  private:
    std::stringstream content;
  };

}

#endif
