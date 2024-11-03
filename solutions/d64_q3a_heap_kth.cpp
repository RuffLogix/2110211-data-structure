#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
    std::vector<T> temp;
    for (int i=0; i<std::min((int)size(), 7); i++) {
        temp.push_back(mData[i]);
    }
    std::sort(temp.begin(), temp.end(), [&](const T& a, const T& b) {
        return !mLess(a, b);
    });
    return temp[k-1];
}

#endif
