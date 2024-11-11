#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T& value) {
    auto itr = begin();
    while (itr != end()) {
        auto temp = itr.ptr->next;
        if (*itr == value) {
            itr.ptr->prev->next = itr.ptr->next;
            itr.ptr->next->prev = itr.ptr->prev;
            delete itr.ptr;
            itr = temp;
            mSize--;
        } else {
            itr++;
        }
    }
}

#endif
