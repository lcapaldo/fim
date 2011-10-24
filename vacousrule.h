#include "rule.h"
namespace fim {
class vacousrule : public rule
{
  public:
  virtual bool test(const fileinfo&);
};
}
