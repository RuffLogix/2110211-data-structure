#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    std::map<T, size_t> storage;
    int index = mFront;
    while (index != (mFront + size()) % mCap) {
        storage[mData[index]] += 1;
        index += 1;
        index %= mCap;
    }

    std::vector<std::pair<T,size_t>> ans;
    for (int i=0; i<k.size(); i++) {
        ans.push_back({k[i], storage[k[i]]});
    }
    return ans;
}

#endif
