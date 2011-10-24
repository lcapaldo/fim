#include "anyrule.h"

namespace fim {
class andrule : public rule
{
   anyrule lhs_;
   anyrule rhs_;

   public:
   andrule(const anyrule& lhs, const anyrule& rhs);
   andrule(const andrule&);
   
   virtual bool test(const fileinfo&);
   
   ~andrule();
};
}
