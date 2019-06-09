// Author: Leonard Bruns (2019)

#ifndef VECTOR_GRAPHICS_PRIMITIVE
#define VECTOR_GRAPHICS_PRIMITIVE

// STL
#include <vector>
#include <memory>

// vector_graphics
// #include "Flag.hpp"
#include "Style.hpp"

namespace vectorgraphics {
  class Primitive;
  typedef std::shared_ptr<Primitive> PrimitivePtr;

  class Primitive {
  public:
    void addStyle(StylePtr style_ptr);
    std::vector<FlagPtr> flag_ptrs;
    std::vector<StylePtr> style_ptrs;
    std::vector<PrimitivePtr> sub_primitive_ptrs_;
  };
}

#endif
