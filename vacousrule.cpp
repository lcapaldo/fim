#include "vacousrule.h"

fim::vacousrule::vacousrule(bool result) : m_result(result)
{}

fim::vacousrule::vacousrule() : m_result(true)
{}


bool fim::vacousrule::test(const fileinfo&)
{
  return m_result;
}
