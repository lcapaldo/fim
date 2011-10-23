#include <string>

namespace fim {

class namerule
{
  struct insensitive_tag_ret { };
  typedef insensitive_tag_ret (*insensitive_tag)();
  public:
  static insensitive_tag insensitive;

  explicit namerule(const std::string& pattern);
  namerule(const std::string& pattern, insensitive_tag);

  ~namerule();

  bool operator()(const std::string& filename) const;

  private:
    std::string pattern_;
    bool caseinsensitive_;

  static insensitive_tag_ret insensitive_tag_keyword();
};
}
