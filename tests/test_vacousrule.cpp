#include "vacousrule.h"
#include "fileinfo.h"

int main()
{
  using namespace fim;
  fileinfo f;
  if( !vacousrule().test(f) ) return 1;
  if( vacousrule(false).test(f) ) return 2;
  if( !vacousrule(true).test(f) ) return 3;
  return 0;
}
