#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
    std::sort(pos.begin(), pos.end());
    int pointer = 0;
    int index = 0;
    for (int i=0; i<mSize; i++) {
        if (index<pos.size() && i==pos[index]) {
            index++;
        } else {
            mData[(mFront + pointer) % mCap] = mData[(mFront + i) % mCap];
            pointer++;
        }
    }
    mSize = pointer;
}

#endif
