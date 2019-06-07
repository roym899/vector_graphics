// Author: Leonard Bruns (2019)
#include "vector_graphics/TikzPlotter.hpp"

#include <iostream>
#include <fstream>

namespace vectorgraphics {
    void TikzPlotter::addPolygon(const Polygon2D& polygon_2d) {

    }

    void TikzPlotter::makePDF(std::filesystem::path path) {
        std::ofstream ofs(path);

        if(!ofs) {
            std::cout << "Error opening output file at " << path << std::endl;
            return;
        }

        ofs << R"(\documentclass[]{standalone})" << std::endl;
        ofs << R"(\usepackage[subpreambles=true]{standalone})" << std::endl;
        ofs << R"(\begin{document})" << std::endl;
        ofs << R"(\begin{tikzpicture})" << std::endl;

        ofs << content.str();

        ofs << R"(\end{tikzpicture})" << std::endl;
        ofs << R"(\end{document})" << std::endl;

        ofs.close();
    }
}