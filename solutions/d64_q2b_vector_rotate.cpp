#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
    int n = last - first;
    if (n == 0 || k == 0) return ;
    T tmp[n];
    int start = first - begin();
    for (int i=0; i<n; i++) {
        tmp[(i - k + n) % n] = mData[start + i];
    }
    for (int i=0; i<n; i++) {
        mData[start + i] = tmp[i];
    }
}

#endif
