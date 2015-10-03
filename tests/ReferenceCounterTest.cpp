#include "lib/ReferenceCounter.h"
#include <iostream>
#include <assert.h>

using namespace std;
using namespace fiber;

class TestCounter : public ReferenceCounter {
 public:
  static TestCounter* make(int* val) {
    return new TestCounter(val);
  }

  ~TestCounter() override {
    *val_ = 0;
  }

 private:
  explicit TestCounter(int* val) : val_(val) {}
  int* val_;
};

void testDestruct() {
  int val = 1;
  auto x = TestCounter::make(&val);
  x->ref();
  assert(val > 0);
  x->unref();
  assert(val > 0);
  x->unref();
  assert(val == 0);
}


main() {
  testDestruct();
  cout << "OK" << endl;
}
