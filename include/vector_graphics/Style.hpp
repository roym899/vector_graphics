// Author: Leonard Bruns (2019)

#ifndef VECTOR_GRAPHICS_STYLE
#define VECTOR_GRAPHICS_STYLE

// STL
#include <string>
#include <memory>
#include <map>
#include <iostream>

// vector_graphics
#include <vector_graphics/Condition.hpp>

namespace vectorgraphics {
  class Style;
  typedef std::shared_ptr<Style> StylePtr;
  typedef std::map<std::string, std::string> StyleMap;

  class Style {
  public:
    Style(const StyleMap& style_map={}, ConditionPtr condition_ptr=nullptr);
    void addKeyValue(std::string key, std::string value);
    void setCondition(ConditionPtr condition_ptr);
    bool conditionFulfilled(const std::vector<FlagPtr> flag_ptrs) const;
    void applyStyle(StyleMap& style_map) const;
  private:
    ConditionPtr condition_ptr_;
    StyleMap style_map_;
  };

  std::string getStyleMapString(const StyleMap& style_map, const std::vector<std::string> keys);

}

#endif
