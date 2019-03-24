// Author: Leonard Bruns (2019)

#ifndef TIKZPLOTTER
#define TIKZPLOTTER

#include <vector>
#include <filesystem>
#include <boost/format.hpp>

#include "Polygon2D.hpp"

class TikzPlotter {
public:
  void addPolygon(const Polygon2D& polygon_2d);
  void makePDF(std::filesystem::path path);
private:
  std::string
  std::stringstream content;
}

#endif
