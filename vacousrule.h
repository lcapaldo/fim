#ifndef H_FIM_VACOUSRULE
#define H_FIM_VACOUSRULE
#include "rule.h"
namespace fim {
class vacousrule : public rule
{
  public:
  vacousrule();
  explicit vacousrule(bool result); 
  virtual bool test(const fileinfo&);
  private:
  bool m_result;
};
}
#endif
