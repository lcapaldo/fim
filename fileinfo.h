#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

namespace fim {
  class fileinfo {
   public:
   ::std::string filename;
   struct stat stat_block;
  };
}
