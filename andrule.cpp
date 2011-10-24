#include "andrule.h"
using namespace fim;

andrule::andrule(const anyrule& lhs, const anyrule& rhs)
: lhs_(lhs), rhs_(rhs)
{}

bool andrule::test(const fileinfo& fi)
{
  return lhs_.test(fi) && rhs_.test(fi);
}

andrule::andrule(const andrule& other)
: lhs_(other.lhs_), rhs_(other.rhs_)
{}

andrule::~andrule()
{}
