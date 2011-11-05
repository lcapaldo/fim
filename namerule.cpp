#include "namerule.h"
#include "fileinfo.h"

using namespace fim;
namerule::namerule(const std::string& pattern) : globrule(pattern)
{}

namerule::namerule(const std::string& pattern, globrule::insensitive_tag t)
: globrule(pattern, t)
{}

namerule::~namerule()
{}

namerule::namerule(const namerule& rhs) : globrule(rhs)
{}

std::string namerule::matchee(const fileinfo& fi)
{
  return fi.filename;
}


