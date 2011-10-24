#include "rule.h"
#include "andrule.h"
#include "statmoderule.h"
#include "namerule.h"
#include "vacousrule.h"
#include <dirent.h>
#include <string.h>

int main(int argc, char **argv)
{
   using namespace fim;
   anyrule rules = vacousrule();
   
   for(int i = 1; i < argc; ++i)
   {
     if( strcmp(argv[i], "-f") == 0 )
     {
        rules = andrule(rules, regularfilerule());
     } else if( strcmp(argv[i], "-d") == 0 ) {
        rules = andrule(rules, directoryrule());
     } else if( strcmp(argv[i], "-name") == 0 ) {
        rules = andrule(rules, namerule(argv[++i]));
     } else if( strcmp(argv[i], "-iname") == 0 ) {
        rules = andrule(rules, namerule(argv[++i], namerule::insensitive));
     }
   }

   DIR *dir = opendir(".");
   dirent *ent;
   fileinfo info;
   while(ent = readdir(dir))
   {
      info.filename = ent->d_name;
      stat(ent->d_name, &info.stat_block);
      if( rules.test(info) )
      {
        printf("%s\n", info.filename.c_str());
      }
   }
   closedir(dir);
   
   return 0;
}
