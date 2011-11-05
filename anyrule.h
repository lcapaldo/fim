#ifndef H_FIM_ANYRULE
#define H_FIM_ANYRULE
#include "rule.h"

namespace fim {
namespace detail {   
template<typename T>
rule* clonerule(rule const* rhs) {
  return new T(*static_cast<T const*>(rhs));
}
}


  class anyrule : public rule {
    rule *proxy_;
    rule* (*cloner_)(rule const*);
    public:
    template<typename T>
      anyrule(const T& rule) 
    : proxy_(new T(rule)), cloner_(&detail::clonerule<T>)
    {}

    ~anyrule(); 
    bool test(const fileinfo& info);

    anyrule(const anyrule& rhs); 

    anyrule& operator=(anyrule rhs);
    private:
      void swap(anyrule& rhs);
  };

} 
#endif
