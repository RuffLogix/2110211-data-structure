#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <cmath>

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
    int n = fmin(size(), other.size());
    int count = 0;
    for (int i=0; i<n; i++) {
        if (mData[i] < other.mData[i]) {
            return true;
        } else if (mData[i] > other.mData[i]) {
            return false;
        } else {
            count += 1;
        }
    }
    return count == size() && size() != other.size();
}

#endif
