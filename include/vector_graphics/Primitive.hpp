// Author: Leonard Bruns (2019)

#ifndef VECTOR_GRAPHICS_PRIMITIVE
#define VECTOR_GRAPHICS_PRIMITIVE

// STL
#include <vector>
#include <memory>

// vector_graphics
// #include "Flag.hpp"
// #include "Style.hpp"

namespace vectorgraphics {
  class Primitive {
  public:
    // std::vector<std::shared_ptr<Flag>> flags_;
    // std::vector<std::shared_ptr<Style>> styles_;
    std::vector<std::shared_ptr<Primitive>> sub_primitives_;
  };
}

#endif
