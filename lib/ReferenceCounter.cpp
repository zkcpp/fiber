#include "lib/ReferenceCounter.h"

namespace fiber {

ReferenceCounter::ReferenceCounter() : rc_(1) {
}

ReferenceCounter::~ReferenceCounter() {
}

void ReferenceCounter::ref() {
  ++rc_;
}

void ReferenceCounter::unref() {
  auto val = rc_.fetch_sub(1);
  if (val == 1) {
    delete this;
  }
}

} // fiber
