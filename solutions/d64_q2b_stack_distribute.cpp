#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <cmath>

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
    std::vector<std::vector<T>> ans;

    int cnt = size() % k;
    int block_size = size() / k;
    std::vector<T> tmp;
    for (int i=0; i<size(); i++) {
        if (tmp.size() == block_size + (cnt > 0)) {
            ans.push_back(tmp);
            tmp.clear();
            cnt--;
        }
        tmp.push_back(mData[size()-i-1]);
    }
    ans.push_back(tmp);
    tmp.clear();

    return ans;
}
#endif
