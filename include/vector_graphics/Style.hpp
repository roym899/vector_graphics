// Author: Leonard Bruns (2019)

#ifndef VECTOR_GRAPHICS_STYLE
#define VECTOR_GRAPHICS_STYLE

// STL
#include <string>
#include <memory>
#include <map>

// vector_graphics
#include <vector_graphics/Condition.hpp>

namespace vectorgraphics {
  class Style {
  public:
    Style(const std::map<std::string, std::string>& style_map={}, ConditionPtr condition_ptr=nullptr);
    void addKeyValue(std::string key, std::string value);
    void setCondition(ConditionPtr condition_ptr);
    bool conditionFulfilled(const std::vector<Flag> flags) const;
  private:
    ConditionPtr condition_ptr_;
    std::map<std::string, std::string> style_map_;
  };
}

#endif
