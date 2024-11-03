#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include <vector>

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
    std::vector<int> remove_position(size() + 1, 0);

    for (std::pair<iterator, iterator> range: ranges) {
        remove_position[range.first - begin()] += 1;
        remove_position[range.second - begin()] -= 1;
    }

    for (int i=1; i<size() + 1; i++) {
        remove_position[i] += remove_position[i-1];
    }

    std::vector<T> temp;
    for (int i=0; i<size(); i++) {
        if (remove_position[i] == 0) {
            temp.push_back(mData[i]);
        }
    }

    for (int i=0; i<temp.size(); i++) {
        mData[i] = temp[i];
    }

    mSize = temp.size();
}

#endif
