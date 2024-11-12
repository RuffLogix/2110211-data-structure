void splitList(list<T>& list1, list<T>& list2) {
    auto iter = begin();
    int n_first = (mSize+1) / 2;

    mHeader->next = mHeader;
    mHeader->prev = mHeader;

    while (iter != end()) {
        auto temp = (iter.ptr->next);

        iter.ptr->next->prev = iter.ptr->prev;
        iter.ptr->prev->next = iter.ptr->next;

        if (n_first > 0) {
            iter.ptr->prev = list1.mHeader->prev;
            iter.ptr->next = list1.mHeader;
            list1.mHeader->prev->next = iter.ptr;
            list1.mHeader->prev = iter.ptr;
            list1.mSize++;
        } else {
            iter.ptr->prev = list2.mHeader->prev;
            iter.ptr->next = list2.mHeader;
            list2.mHeader->prev->next = iter.ptr;
            list2.mHeader->prev = iter.ptr;
            list2.mSize++;
        }

        n_first--;
        mSize--;
        iter = temp;
    }
}
