// Author: Leonard Bruns (2019)
#include "vector_graphics/Primitive.hpp"

namespace vectorgraphics {
  void Primitive::addStyle(StylePtr style_ptr) {
    style_ptrs.push_back(style_ptr);
  }
}