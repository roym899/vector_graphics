// Author: Leonard Bruns (2019)

#ifndef VECTOR_GRAPHICS_CONDITION
#define VECTOR_GRAPHICS_CONDITION

// STL
#include <string>
#include <vector>
#include <memory>

// vector_graphics
#include "vector_graphics/Flag.hpp"

namespace vectorgraphics {
  class Condition {
  public:
    virtual bool fulfilled(const std::vector<Flag>& flags) const =0;
  private:
  };
  typedef std::shared_ptr<Condition> ConditionPtr;

  class TrueCondition : public Condition {
  public:
    virtual bool fulfilled(const std::vector<Flag>& flags) const;
  private:
  };

  class OrCondition : public Condition {
  public:
    OrCondition(const std::vector<ConditionPtr>& condition_ptrs);
    virtual bool fulfilled(const std::vector<Flag>& flags) const;
  private:
    std::vector<ConditionPtr> condition_ptrs_;
  };

  class AndCondition : public Condition {
  public:
    AndCondition(const std::vector<ConditionPtr>& condition_ptrs);
    virtual bool fulfilled(const std::vector<Flag>& flags) const;
  private:
    std::vector<ConditionPtr> condition_ptrs_;
  };

  class FlagCondition : public Condition {
  public:
    FlagCondition(const Flag& flag);
    virtual bool fulfilled(const std::vector<Flag>& flags) const;
  private:
    Flag flag_;
  };
}

#endif
