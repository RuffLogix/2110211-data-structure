#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure
#include <set>

template <typename T>
void CP::vector<T>::uniq() {
    std::set<T> s;
    vector<T> tmp;
    for (int i=0; i<mSize; i++) {
        if (s.find(at(i)) != s.end()) continue;
        s.insert(at(i));
        tmp.push_back(at(i));
    }
    for (int i=0; i<tmp.mSize; i++) {
        mData[i] = tmp.at(i);
    }
    mSize = tmp.mSize;
    mCap = tmp.mCap;
}

#endif
