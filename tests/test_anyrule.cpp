#include "statmoderule.h"
#include "anyrule.h"
#include "namerule.h"

int main()
{
   using namespace fim;
   fileinfo fi;
   stat("./tests.sh", &fi.stat_block);
   directoryrule d;
   anyrule ad(d);
   
   if( ad.test(fi) ) return 1;
   regularfilerule r;
   anyrule ar(r);
   if( !ar.test(fi) ) return 1;
   fileinfo di;
   stat(".", &di.stat_block);
   if( !ad.test(di) ) return 1;
   namerule nr("abc");
   anyrule anr(nr);
   di.filename = "abc";
   if( !anr.test(di) ) return 1;
   return 0;
}
