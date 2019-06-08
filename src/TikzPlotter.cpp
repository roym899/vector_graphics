// Author: Leonard Bruns (2019)
#include "vector_graphics/TikzPlotter.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>

namespace vectorgraphics {
    void TikzPlotter::addPolygon(const Polygon2D& polygon_2d) {

    }

    void TikzPlotter::makePDF(std::filesystem::path path, std::string name) {
        std::string tex_name = name + ".tex";
        std::filesystem::path full_tex_path = path / tex_name;

        // create directories
        std::filesystem::create_directories(path);

        // clean up before, in case there are some left over files
        cleanup(path, name);

        if(createTexFile(full_tex_path)) {
            if(compileTexFile(path, name)) {
                std::cout << "makePDF: PDF succesfully created at " << full_tex_path << std::endl;
            }
        }

        // clean up after
        cleanup(path, name);
    }

    bool TikzPlotter::createTexFile(std::filesystem::path tex_path) const {
        std::ofstream ofs(tex_path);

        if(!ofs) {
            std::cout << "Error in createTexFile: opening output file at " << tex_path << std::endl;
            return false;
        }

        ofs << R"(\documentclass[]{standalone})" << std::endl;
        ofs << R"(\usepackage[subpreambles=true]{standalone})" << std::endl;
        ofs << R"(\begin{document})" << std::endl;

        ofs << R"(test)" << std::endl;

        if(content.str().size() != 0) {
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
        oss << "cd " << path << " && lualatex --halt-on-error " << path / (name+".tex") << ">/dev/null";
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
}