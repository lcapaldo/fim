#ifndef H_FIM_FILEINFO
#define H_FIM_FILEINFO
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

namespace fim {
  class fileinfo {
   public:
   ::std::string filename;
   ::std::string dirname;
   struct stat stat_block;
  };
}
#endif
