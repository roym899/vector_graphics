// Author: Leonard Bruns (2019)

// vector_graphics
#include "vector_graphics/TikzPlotter.hpp"

// STL
#include <iostream>
#include <fstream>
#include <cstdlib>

namespace vectorgraphics
{
  void TikzPlotter::addPolygon(const Polygon2D &polygon_2d) {
    // first add the polygon

    // and then the outline

  }

  void TikzPlotter::addLineSegment(const LineSegment2D &line_segment_2d) {
    // first add the line
    StyleMap style_map;

    // check which styles apply
    for(const auto& style_ptr : line_segment_2d.style_ptrs) {
      if(style_ptr->conditionFulfilled(line_segment_2d.flag_ptrs)) {
        style_ptr->applyStyle(style_map);
      }
    }


    // add the line based on style_map final state
    if(style_map.find("draw") != style_map.end() || style_map.find("fill") != style_map.end()) {
      content << R"(\path[)" 
        << getStyleMapString(style_map, {"draw", "draw opacity", "fill", "fill opacity", "line width", "line cap", "dash pattern", "*line_path"})
        << "] " 
        << *line_segment_2d.start_ptr_ 
        << " -- " 
        << *line_segment_2d.end_ptr_
        << ";"
        << std::endl;
    }

    // next add the endpoints
    addPoint(*line_segment_2d.start_ptr_);
    addPoint(*line_segment_2d.end_ptr_);
  }

  void TikzPlotter::addPoint(const Point2D &point_2d) {
    StyleMap style_map;

    // check which styles apply
    for(const auto& style_ptr : point_2d.style_ptrs) {
      if(style_ptr->conditionFulfilled(point_2d.flag_ptrs)) {
        style_ptr->applyStyle(style_map);
      }
    }

    // add the point based on style_map final state
    if(style_map.find("draw") != style_map.end() || style_map.find("fill") != style_map.end()) {
      content << R"(\path[)" 
        << getStyleMapString(style_map, {"draw", "draw opacity", "fill", "fill opacity", "line width", "*point_path"})
        << "] " 
        << point_2d 
        << "circle [" 
        << getStyleMapString(style_map, {"radius", "*point_circle"})
        << "];" 
        << std::endl;
    }
  }

  void TikzPlotter::makePDF(std::filesystem::path path, std::string name) {
    std::string tex_name = name + ".tex";
    std::filesystem::path full_tex_path = path / tex_name;

    // create directories
    std::filesystem::create_directories(path);

    // clean up before, in case there are some left over files
    cleanup(path, name);

    if (createTexFile(full_tex_path)) {
      if (compileTexFile(path, name)) {
        std::cout << "makePDF: PDF succesfully created at " << full_tex_path << std::endl;
      }
    }

    // clean up after
    cleanup(path, name);
  }

  bool TikzPlotter::createTexFile(std::filesystem::path tex_path) const {
    std::ofstream ofs(tex_path);

    if (!ofs) {
      std::cout << "Error in createTexFile: opening output file at " << tex_path << std::endl;
      return false;
    }

    ofs << R"(\documentclass[]{standalone})" << std::endl;
    ofs << R"(\usepackage[subpreambles=true]{standalone})" << std::endl;
    ofs << R"(\usepackage{tikz})" << std::endl;
    ofs << R"(\begin{document})" << std::endl;

    if (content.str().size() != 0) {
      ofs << R"(\begin{tikzpicture})" << std::endl;

      ofs << content.str();

      ofs << R"(\end{tikzpicture})" << std::endl;
    }
    ofs << R"(\end{document})" << std::endl;

    ofs.close();
    return true;
  }

  bool TikzPlotter::compileTexFile(std::filesystem::path path, std::string name) const {
    std::ostringstream oss;
    oss << "cd " << path << " && lualatex --halt-on-error " << (name + ".tex") << ">/dev/null";
    auto ret = std::system(oss.str().c_str());
    if (ret != 0) {
      std::cout << "Error in compileTexFile: lualatex call not succesful" << std::endl;
      return false;
    }
    return true;
  }

  bool TikzPlotter::cleanup(std::filesystem::path path, std::string name) {
    bool success = true;
    success &= std::filesystem::remove(path / (name + ".aux"));
    success &= std::filesystem::remove(path / (name + ".log"));
    success &= std::filesystem::remove(path / (name + ".sta"));
    return success;
  }
} // namespace vectorgraphics