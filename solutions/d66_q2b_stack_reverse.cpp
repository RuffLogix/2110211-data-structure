#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

template <typename T>
void CP::stack<T>::reverse(size_t first, size_t last){
    if (first > last) return;

    last = std::min(size() - 1, last);
    first = std::min(size() - 1, first);

    first = size() - 1 - first;
    last = size() - 1 - last;

    for (int i=0; i<(first-last+1)/2; i++) {
        std::swap(mData[last+i], mData[first-i]);
    }
}

#endif
