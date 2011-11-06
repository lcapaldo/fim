#ifndef H_PATH_RULE
#define H_PATH_RULE
#include "globrule.h"

namespace fim {
class pathrule : public globrule
{
  public:
  explicit pathrule(const std::string& pattern);
  pathrule(const std::string& pattern, globrule::insensitive_tag);
  
  pathrule(const pathrule& );
  ~pathrule();
  
  private:
  std::string matchee(const fileinfo&);
};
}
#endif
