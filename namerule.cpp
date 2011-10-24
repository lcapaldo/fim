#include "namerule.h"
#include <fnmatch.h>
#include <cstdlib>
#include "fileinfo.h"

using namespace fim;
using std::string;


namerule::insensitive_tag namerule::insensitive = &namerule::insensitive_tag_keyword;

namerule::namerule(const string& pattern) : pattern_(pattern), caseinsensitive_(false)
{}

namerule::namerule(const string& pattern, namerule::insensitive_tag)
: pattern_(pattern), caseinsensitive_(true)
{}

namerule::~namerule()
{}

bool namerule::operator()(const std::string& filename) const
{
   return fnmatch(pattern_.c_str(), filename.c_str(), 
       caseinsensitive_ ? FNM_CASEFOLD : 0) == 0; 
}

bool namerule::test(const fileinfo& info)
{
   return (*this)(info.filename);
}


namerule::insensitive_tag_ret namerule::insensitive_tag_keyword() { std::abort(); }

