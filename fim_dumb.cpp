#include "rule.h"
#include "andrule.h"
#include "statmoderule.h"
#include "namerule.h"
#include "vacousrule.h"
#include "pathrule.h"
#include <dirent.h>
#include <string.h>
#include <iostream>

using namespace fim;

std::string fullpath(std::string dirname, std::string filename)
{
  return dirname + "/" + filename;
}

template <typename F>
void traverse_dir_rec(std::string dirname, DIR *dir, anyrule& rules, F onhit)
{
  dirent *ent;
  fileinfo info;
  while(ent = readdir(dir))
  {
    info.filename = ent->d_name;
    info.dirname = dirname;
    stat(ent->d_name, &info.stat_block);
    if( rules.test(info) )
    {
      onhit(info);
    }
    if( directoryrule().test(info) && 
        !pathrule("*/.").test(info) && 
        !pathrule("*/..").test(info) )
    {
      std::string dirname = fullpath(info.dirname, info.filename);
      DIR *dir1 = opendir(dirname.c_str());
      if (dir1)traverse_dir_rec(dirname, dir1, rules, onhit);
      if (dir1) closedir(dir1);
    } 
  }
}

void printit(const fileinfo& fi) 
{
  std::cout << fullpath(fi.dirname, fi.filename) << std::endl;
}

int main(int argc, char **argv)
{
   anyrule rules = vacousrule<>();
   
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
     } else if( strcmp(argv[i], "-true") == 0 ) {
        rules = andrule(rules, vacousrule<>());
     } else if( strcmp(argv[i], "-false") == 0 ) {
       rules = andrule(rules, vacousrule<false>());
     } else if( strcmp(argv[i], "-ipath") == 0 ) {
       rules = andrule(rules, pathrule(argv[++i], globrule::insensitive));
     } else if( strcmp(argv[i], "-path") == 0 ) {
       rules = andrule(rules, pathrule(argv[++i]));
     }
   }

   DIR *dir = opendir(".");
   traverse_dir_rec(".", dir, rules, &printit);   
   closedir(dir);
   
   return 0;
}
