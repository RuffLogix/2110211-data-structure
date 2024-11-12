#ifndef __STUDENT_H__
#define __STUDENT_H__


template <typename T>
bool CP::list<T>::check() {
    auto iter = begin();
    int temp = mSize;

    while (iter != end() && iter!=NULL) {
        temp--;
        if (temp < 0) return false;
        if (iter.ptr->next != NULL &&
            iter.ptr->prev != NULL &&
            iter.ptr->next->prev == iter.ptr &&
            iter.ptr->prev->next == iter.ptr) {
          iter++;
        }
    }
    if (temp > 0) return false;

    return true;
}


#endif
