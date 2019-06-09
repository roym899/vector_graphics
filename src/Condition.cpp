// Author: Leonard Bruns (2019)
#include "vector_graphics/Condition.hpp"

namespace vectorgraphics {
  // TrueCondition
  bool TrueCondition::fulfilled(const std::vector<FlagPtr>& flag_ptrs) const {
    return true;
  }

  // OrCondition
  OrCondition::OrCondition(const std::vector<ConditionPtr>& condition_ptrs) :
    condition_ptrs_(condition_ptrs) {

  }
  bool OrCondition::fulfilled(const std::vector<FlagPtr>& flag_ptrs) const {
    for(const auto &condition_ptr : condition_ptrs_) {
      if(!condition_ptr->fulfilled(flag_ptrs))
        return true;
    }
    return false;
  }

  // AndCondition
  AndCondition::AndCondition(const std::vector<ConditionPtr>& condition_ptrs) :
    condition_ptrs_(condition_ptrs) {

  }
  bool AndCondition::fulfilled(const std::vector<FlagPtr>& flag_ptrs) const {
    for(const auto &condition_ptr : condition_ptrs_) {
      if(!condition_ptr->fulfilled(flag_ptrs))
        return false;
    }
    return true;
  }

  // FlagCondition
  FlagCondition::FlagCondition(const FlagPtr& flag_ptr) :
    flag_ptr_(flag_ptr) {

  }
  bool FlagCondition::fulfilled(const std::vector<FlagPtr>& flag_ptrs) const {
    // TODO, when Flag interface is done
    return true;
  }
}