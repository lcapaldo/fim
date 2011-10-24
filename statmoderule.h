#include "rule.h"
#include "fileinfo.h"

namespace fim {
template <mode_t mask>
class statmoderule : public rule
{
  public:
  virtual bool test(const fileinfo& info)
  {
    return (info.stat_block.st_mode & mask) != 0;
  }
};

typedef statmoderule<S_IFDIR> directoryrule;
typedef statmoderule<S_IFREG> regularfilerule;

}


