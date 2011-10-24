#include "rule.h"

namespace fim {
namespace detail {   
    class cloneablerule : public rule {
      public:
      virtual cloneablerule* clone() = 0;
    };
    template<typename T>
      class ruleeraser : public cloneablerule {
        T* rule_impl_;
        public:
        ruleeraser(T* rule) : rule_impl_(rule)
        {}

        ~ruleeraser()
        { delete rule_impl_; }

        virtual bool test(const fileinfo& info)
        { return rule_impl_->test(info); }

        virtual cloneablerule* clone()
        { return new ruleeraser<T>(new T(*rule_impl_)); }
      };
  }


  class anyrule : public rule {
    detail::cloneablerule *proxy_;
    public:
    template<typename T>
      explicit anyrule(T rule) 
    : proxy_(new detail::ruleeraser<T>(new T(rule)))
    {}

    ~anyrule(); 
    bool test(const fileinfo& info);

    anyrule(const anyrule& rhs); 
  };

} 
