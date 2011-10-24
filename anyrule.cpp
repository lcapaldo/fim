#include "anyrule.h"
#include <utility>
using namespace fim;

bool anyrule::test(const fileinfo& info)
{
  return proxy_->test(info);
}


anyrule::anyrule(const anyrule& rhs)
: proxy_(rhs.proxy_->clone())
{}

anyrule::~anyrule()
{
  delete proxy_;
}

anyrule& anyrule::operator=(anyrule rhs)
{
  swap(rhs);
}

void anyrule::swap(anyrule& rhs)
{
  std::swap(proxy_, rhs.proxy_);
}
