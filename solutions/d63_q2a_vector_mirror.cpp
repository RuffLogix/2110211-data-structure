#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
    T *temp = new T[mSize*2]();
    for (int i=0; i<mSize; i++) {
        temp[i] = mData[i];
    }

    for (int i=mSize-1; i>=0; i--) {
        temp[mSize+((mSize-1)-i)] = mData[i];
    }

    delete [] mData;
    mData = temp;
    mSize *= 2;
    if (mSize > mCap) mCap *= 2;
}

#endif
