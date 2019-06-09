// Author: Leonard Bruns (2019)
#include "vector_graphics/Condition.hpp"

namespace vectorgraphics {
  // TrueCondition
  bool TrueCondition::fulfilled(const std::vector<Flag>& flags) const {
    return true;
  }

  // OrCondition
  OrCondition::OrCondition(const std::vector<ConditionPtr>& condition_ptrs) :
    condition_ptrs_(condition_ptrs) {

  }
  bool OrCondition::fulfilled(const std::vector<Flag>& flags) const {
    for(const auto &condition_ptr : condition_ptrs_) {
      if(!condition_ptr->fulfilled(flags))
        return true;
    }
    return false;
  }

  // AndCondition
  AndCondition::AndCondition(const std::vector<ConditionPtr>& condition_ptrs) :
    condition_ptrs_(condition_ptrs) {

  }
  bool AndCondition::fulfilled(const std::vector<Flag>& flags) const {
    for(const auto &condition_ptr : condition_ptrs_) {
      if(!condition_ptr->fulfilled(flags))
        return false;
    }
    return true;
  }

  // FlagCondition
  FlagCondition::FlagCondition(const Flag& flag) :
    flag_(flag) {

  }
  bool FlagCondition::fulfilled(const std::vector<Flag>& flags) const {
    // TODO, when Flag interface is done
    return true;
  }
}