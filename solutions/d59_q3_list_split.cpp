#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
    CP::list<T> result;

    if (pos != mSize) {
        auto temp = it; temp--;
        result.mHeader->next = it.ptr;
        result.mHeader->prev = mHeader->prev;
        result.mHeader->next->prev = result.mHeader;
        result.mHeader->prev->next = result.mHeader;
        it = temp;
        mHeader->prev = it.ptr;
        it.ptr->next = mHeader;
    }

    result.mSize = mSize - pos;
    mSize = pos;

    return result;
}

#endif
