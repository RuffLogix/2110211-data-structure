#ifndef __STUDENT_H_
#define __STUDENT_H_


#include <algorithm>
#include <vector>
template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::operator==(const CP::priority_queue<T,Comp> &other) const {
    if (size() != other.size()) return false;
    std::vector<T> v1(size()), v2(size());
    for (int i=0; i<size(); i++) v1[i] = mData[i], v2[i] = other.mData[i];
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    if (size() != 0 && mLess(v1.front(), v1.back()) != other.mLess(v2.front(), v2.back())) return false;
    return v1 == v2;
}

#endif
