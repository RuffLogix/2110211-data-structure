#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <utility>

template <typename T>
void CP::stack<T>::mitosis(int a, int b) {
    size_t new_size = b-a+1;
    b = size() - b - 1;
    a = size() - a - 1;
    if (new_size + size() > mCap) {
        expand(std::max(new_size + size(), mCap * 2));
    }
    int l = mSize - 1, r = new_size + size() - 1;
    while (l > a) {
        mData[r--] = mData[l--];
    }
    while (l >= b) {
       mData[r--] = mData[l];
       mData[r--] = mData[l--];
    }
    mSize = new_size + size();
}

#endif
