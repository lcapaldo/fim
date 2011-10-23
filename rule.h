namespace fim {

class fileinfo;

class rule {
  public:
  virtual bool test(const fileinfo& info) = 0;
  virtual ~rule();
};
}
