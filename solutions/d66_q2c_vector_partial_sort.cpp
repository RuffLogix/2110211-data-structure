#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
template <typename T>
template <typename CompareT>
void CP::vector<T>::partial_sort(std::vector<iterator> &pos,CompareT  comp) {
  std::vector<T> temp;
  for (auto itr: pos) temp.push_back(*itr);
  std::sort(temp.begin(), temp.end(), comp);
  std::sort(pos.begin(), pos.end());
  int index = 0;
  for (auto itr: pos) *itr = temp[index++];
}

#endif
