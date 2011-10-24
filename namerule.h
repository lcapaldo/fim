#include <string>
#include "rule.h"

namespace fim {

class namerule : public rule
{
  struct insensitive_tag_ret { };
  typedef insensitive_tag_ret (*insensitive_tag)();
  public:
  static insensitive_tag insensitive;

  explicit namerule(const std::string& pattern);
  namerule(const std::string& pattern, insensitive_tag);

  ~namerule();

  bool operator()(const std::string& filename) const;
  virtual bool test(const fileinfo& info);

  private:
    std::string pattern_;
    bool caseinsensitive_;

  static insensitive_tag_ret insensitive_tag_keyword();
};
}
