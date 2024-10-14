#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::back_to_front() {
  int last = ((int)mFront + (int)mSize - 1) % mCap;
  mData[(int(mFront) - 1) % mCap] = mData[last];
  mFront = ((int)mFront - 1) % mCap;
}

#endif
