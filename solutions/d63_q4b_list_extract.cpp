#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
    auto itr = a;

    while (itr != b) {
        if (*itr == value)  {
            auto temp = itr;
            temp++;

            itr.ptr->prev->next = itr.ptr->next;
            itr.ptr->next->prev = itr.ptr->prev;

            itr.ptr->prev = output.mHeader->prev;
            itr.ptr->next = output.mHeader;
            output.mHeader->prev->next = itr.ptr;
            output.mHeader->prev = itr.ptr;
            output.mSize++;

            mSize--;
            itr = temp;
        } else {
            itr++;
        }
    }
}

#endif
