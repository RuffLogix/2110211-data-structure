#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>


template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixUp(size_t idx) {
    T temp = mData[idx];
    int index = idx;
    while (index > 0) {
        if (!mLess(temp, mData[(index-1)/4])) {
            mData[index] = mData[(index-1)/4];
            index = (index-1)/4;
        } else {
            break;
        }
    }
    mData[index] = temp;
}

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixDown(size_t idx) {
    T temp = mData[idx];
    int index = idx;
    while (index*4 + 1 < size()) {
        int new_index = index*4 + 1;
        for (int i=2; i<=4; i++) {
            if (index*4 + i < size() && mLess(mData[new_index], mData[index*4 + i])) {
                new_index = index*4 + i;
            }
        }
        if (mLess(mData[new_index], temp)) break;
        mData[index] = mData[new_index];
        index = new_index;
    }
    mData[index] = temp;
}

#endif
