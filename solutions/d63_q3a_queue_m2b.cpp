#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
    int last = (mFront + size() - 1) % mCap;
    while (last != (mFront + pos) % mCap) {
        std::swap(mData[last], mData[(mFront + pos) % mCap]);
        last -= 1;
        if (last < 0) last = mCap - 1;
    }
}

#endif
