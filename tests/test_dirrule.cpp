#include "statmoderule.h"

int main()
{
   using namespace fim;
   fileinfo fi;
   stat("./tests.sh", &fi.stat_block);
   directoryrule d;
   if( d.test(fi) ) return 1;
   regularfilerule r;
   if( !r.test(fi) ) return 1;
   return 0;
}
