#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    int temp_front = mFront;
    while (temp_front != (pos + mFront) % mCap) {
        std::swap(mData[temp_front], mData[(pos + mFront) % mCap]);
        temp_front += 1;
        temp_front %= mCap;
    }
}

#endif
