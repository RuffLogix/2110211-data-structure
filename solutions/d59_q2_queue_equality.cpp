#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::queue<T>::operator==(const CP::queue<T> &other) const {
    if (size() != other.size()) return false;

    bool ans = true;
    for (int i=0; i<size(); i++) {
        ans &= mData[(mFront + i) % mCap] == other.mData[(other.mFront + i) % other.mCap];
    }
    return ans;
}

#endif
