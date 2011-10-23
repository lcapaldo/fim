#include <iostream>
#include "namerule.h"
int main()
{
  using namespace fim;
  
  namerule star("*");
  if(!star("a")) return 1;
  if(!star("abc")) return 1;
  
  namerule abc("abc", namerule::insensitive);
  if(!abc("Abc")) return 1;
  if(!abc("abc")) return 1;
  if(!abc("ABC")) return 1;


  namerule q("a?b");
  if(!q("acb")) return 1;
  if(q("ab")) return 1;
  if(q("ccc")) return 1;
  if(!q("a7b")) return 1;

  return 0;
}
  
