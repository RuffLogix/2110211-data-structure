#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <cmath>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  //write your code here
  //can include anything
  std::vector<T> r;
  int index = std::pow(2, k) - 1;
  int _size = std::pow(2, k);

  for (int i=0; i<_size; i++) {
      if (index + i >= size()) break;
      r.push_back(mData[index + i]);
  }

  std::sort(r.begin(), r.end(), [&](const T& a, const T& b) {
      return !mLess(a, b);
  });

  return r;
}

#endif
