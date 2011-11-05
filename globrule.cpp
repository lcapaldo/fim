#include "namerule.h"
#include <fnmatch.h>
#include <cstdlib>
#include "fileinfo.h"

using namespace fim;
using std::string;


const globrule::insensitive_tag globrule::insensitive = &globrule::insensitive_tag_keyword;

globrule::globrule(const string& pattern) : pattern_(pattern), caseinsensitive_(false)
{}

globrule::globrule(const string& pattern, globrule::insensitive_tag)
: pattern_(pattern), caseinsensitive_(true)
{}

globrule::globrule(const globrule& rhs)
: pattern_(rhs.pattern_), caseinsensitive_(rhs.caseinsensitive_)
{}

globrule::~globrule()
{}

bool globrule::operator()(const std::string& filename) const
{
   return fnmatch(pattern_.c_str(), filename.c_str(), 
       caseinsensitive_ ? FNM_CASEFOLD : 0) == 0; 
}

bool globrule::test(const fileinfo& info)
{
   return (*this)(matchee(info));
}


globrule::insensitive_tag_ret globrule::insensitive_tag_keyword() { std::abort(); }

