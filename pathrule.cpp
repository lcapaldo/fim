#include "pathrule.h"
#include "fileinfo.h"

using namespace fim;

pathrule::pathrule(const std::string& pattern) : globrule(pattern)
{}

pathrule::pathrule(const std::string& pattern, globrule::insensitive_tag t)
: globrule(pattern, t)
{}

pathrule::pathrule(const pathrule& rhs) : globrule(rhs)
{}

pathrule::~pathrule()
{}

std::string pathrule::matchee(const fileinfo& fi)
{
  return fi.dirname + "/" + fi.filename;
}

