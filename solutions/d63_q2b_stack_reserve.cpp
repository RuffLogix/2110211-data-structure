#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    int reserve = mCap - size();
    int otherReserve = other.mCap - other.size();

    if (reserve == otherReserve) return 0;
    if (reserve < otherReserve) return -1;
    return 1;
}

#endif
