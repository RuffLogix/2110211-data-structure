#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <set>

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
    std::set<int> s_pos;
    for (int i=0; i<pos.size(); i++) {
        s_pos.insert(pos.at(i));
    }
    std::set<int>::iterator iter = s_pos.begin();
    vector<int> tmp;
    for (int i=0; i<size(); i++) {
        if (i==*iter) {
            iter ++;
            continue;
        }
        tmp.push_back(at(i));
    }
    for (int i=0; i<tmp.size(); i++) {
        mData[i] = tmp.at(i);
    }
    mSize = tmp.mSize;
    mCap = tmp.mCap;
}

#endif
