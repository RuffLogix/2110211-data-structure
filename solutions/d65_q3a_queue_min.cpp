#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  T ans;
  bool check = false;
  for (size_t i=0; i<pos.size(); i++) {
      if (pos[i] >= size()) continue;

      T data = mData[(mFront + pos[i]) % mCap];
      if (!check) ans = data;
      else if (comp(data, ans)) ans = data;
      check = true;
  }
  return ans;
}

#endif
