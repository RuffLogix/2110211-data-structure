#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
    int ans = 0;
    int n_same = 0;
    for (int i=0; i<size(); i++) {
        ans += mLess(mData[i], mData[pos]);
        n_same += (mData[i] == mData[pos]);
    }
    return size() - ans - n_same;
}

#endif
