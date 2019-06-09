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
    Style();
    Style(const std::map<std::string, std::string> styleMap, std::shared_ptr<Condition> condition_ptr=nullptr);
    void addKeyValue(std::string key, std::string value);
    void setCondition(std::shared_ptr<Condition> condition_ptr);
  private:
    std::shared_ptr<Condition> condition_ptr_;
    std::map<std::string, std::string> styleMap;
  };
}

#endif
