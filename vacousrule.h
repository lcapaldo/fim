#ifndef H_FIM_VACOUSRULE
#define H_FIM_VACOUSRULE
#include "rule.h"
namespace fim {
class vacousrule : public rule
{
  public:
  virtual bool test(const fileinfo&);
};
}
#endif
