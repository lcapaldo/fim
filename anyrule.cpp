#include "anyrule.h"
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
