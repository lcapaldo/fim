#ifndef H_FIM_GLOBRULE
#define H_FIM_GLOBRULE
#include <string>
#include "rule.h"

namespace fim {

class globrule : public rule
{
  struct insensitive_tag_ret { };
  protected:
  typedef insensitive_tag_ret (*insensitive_tag)(); 
  public:
  static const insensitive_tag insensitive;

  explicit globrule(const std::string& pattern);
  globrule(const std::string& pattern, insensitive_tag);
  globrule(const globrule&);

  ~globrule();

  bool operator()(const std::string& filename) const;
  virtual bool test(const fileinfo& info);

  private:
    virtual std::string matchee(const fileinfo& ) = 0;
    std::string pattern_;
    bool caseinsensitive_;
  static insensitive_tag_ret insensitive_tag_keyword();
};
}
#endif
