#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
    int upper = std::upper_bound(aux.begin(), aux.end(), idx) - aux.begin() - 1;
    return mData[upper][idx - aux[upper]];
}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
    if (aux.size() == 0) aux.push_back(0);
    aux.push_back(mData.back().size());
    aux[aux.size() - 1] += aux[aux.size() - 2];
}

#endif
