#include "anyrule.h"
#include <utility>
using namespace fim;

bool anyrule::test(const fileinfo& info)
{
  return proxy_->test(info);
}


anyrule::anyrule(const anyrule& rhs)
: proxy_(rhs.cloner_(rhs.proxy_)), cloner_(rhs.cloner_)
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
  std::swap(cloner_, rhs.cloner_);
}
