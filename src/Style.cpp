// Author: Leonard Bruns (2019)
#include "vector_graphics/Style.hpp"
namespace vectorgraphics {
  Style::Style(const std::map<std::string, std::string>& style_map, ConditionPtr condition_ptr) :
    style_map_(style_map),
    condition_ptr_(condition_ptr) {
  }

  void Style::addKeyValue(std::string key, std::string value) {
    style_map_[key] = value;
  }

  void Style::setCondition(ConditionPtr condition_ptr) {
    condition_ptr_ = condition_ptr;
  }

  bool Style::conditionFulfilled(const std::vector<Flag> flags) const {
    if(condition_ptr_ != nullptr) {
      return condition_ptr_->fulfilled(flags);
    }
    else {
      return true;
    }
  }
}