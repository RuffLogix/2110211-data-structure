#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "stack.h"
#include <cmath>

template <typename T>
void CP::stack<T>::v_split(std::vector<std::stack<T>> &output, size_t k) const {
    int current_size = size();
    for (int i=0; i<k; i++) {
        int segment_size = std::ceil((double) current_size / (k - i));
        std::stack<T> temp;
        for (int j=0; j<segment_size; j++) {
            temp.push(mData[current_size - segment_size + j]);
        }
        current_size -= segment_size;
        output.push_back(temp);
    }
}

#endif
