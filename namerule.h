#ifndef H_FIM_NAMERULE
#define H_FIM_NAMERULE

#include "globrule.h"
namespace fim {
class namerule : public globrule
{
  public:
  explicit namerule(const std::string& pattern);
  namerule(const std::string& pattern, globrule::insensitive_tag);
  namerule(const namerule&);
  
  ~namerule();
  private:
  virtual std::string matchee(const fileinfo& fileinfo);
};
}
#endif
 
