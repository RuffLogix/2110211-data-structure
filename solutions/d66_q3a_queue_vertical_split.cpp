#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <cmath>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::v_split(std::vector<std::queue<T>> &output, size_t k) const
{
    int current_size = mSize;
    int index = 0;
    for (int i=0; i<k; i++) {
        int segment_size = std::ceil((double)current_size / (k - i));
        std::queue<T> temp;
        while (segment_size--) {
            temp.push(mData[(mFront + index) % mCap]);
            index++;
        }
        current_size -= temp.size();
        output.push_back(temp);
    }
}

#endif
