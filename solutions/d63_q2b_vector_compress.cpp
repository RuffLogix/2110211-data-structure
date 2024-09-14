#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    mCap = mSize;
    T *temp = new T[mSize]();
    for (int i=0; i<mSize; i++) {
        temp[i] = mData[i];
    }
    delete [] mData;
    mData = temp;
}

#endif
