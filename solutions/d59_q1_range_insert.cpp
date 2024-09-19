#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  T *tmp = new T[size() + (last - first)]();
  int index=0;
  for (int i=0; i<=size(); i++) {
      if (begin()+i == position) {
          for (iterator j=first; j<=last-1; j++) {
              tmp[index++] = *j;
          }
      }
      if (i!=size()) tmp[index++] = mData[i];
  }
  delete [] mData;
  mData = tmp;
  mSize = size() + (last - first);
  mCap = mSize;
}

#endif
