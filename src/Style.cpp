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

  bool Style::conditionFulfilled(const std::vector<FlagPtr> flag_ptrs) const {
    if(condition_ptr_ != nullptr) {
      return condition_ptr_->fulfilled(flag_ptrs);
    }
    else {
      return true;
    }
  }

  void Style::applyStyle(StyleMap& style_map) const {
    for(const auto& style_pair : style_map_) {
      style_map[style_pair.first] = style_pair.second;
    }
  }

  std::string getStyleMapString(const StyleMap& style_map, const std::vector<std::string> keys) {
    std::string full_string{""};
    for(const auto& key : keys) {
      if(style_map.find(key) != style_map.end()) {
        if(key[0] == '*') { // starred parameters will not add the key (this is to support unique / special parameters )
          full_string += style_map.at(key);
          full_string += ",";
        }
        else {
          full_string += key;
          full_string += "=";
          full_string += style_map.at(key);
          full_string += ",";
        }
      }
    }
    return full_string;
  }
}