#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  std::sort(data.begin(), data.end());
  CP::vector<T> tmp;

  int idx = 0;
  for (int i=0; i<=size(); i++) {
      if (idx != data.size() && data[idx].first == i) {
          tmp.push_back(data[idx].second);
          idx += 1;
      }
      if (i!=size()) tmp.push_back(at(i));
  }

  expand(tmp.size());

  for (int i=0; i<tmp.size(); i++) {
      if (i<size()) mData[i] = tmp[i];
      else push_back(tmp[i]);
  }
}

#endif
