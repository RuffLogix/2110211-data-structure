#ifndef __STUDENT_H
#define __STUDENT_H

#include "priority_queue.h"
#include <stack>

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::check() {
  std::stack<size_t> pos;
  pos.push(0);
  while (pos.size()) {
    int index = pos.top(); pos.pop();
    if (index >= size()) continue;

    if (index*2 + 1 < size()) {
        if (mLess(mData[index], mData[index*2 + 1])) return false;
        pos.push(index*2 + 1);
    }
    if (index*2 + 2 < size()) {
        if (mLess(mData[index], mData[index*2 + 2])) return false;
        pos.push(index*2 + 2);
    }
  }
  return true;
}

#endif
