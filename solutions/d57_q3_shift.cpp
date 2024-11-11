void update_list(int k) {
    auto itr = begin();
    while (k--) {
        itr++;
    }
    mHeader->next->prev = mHeader->prev;
    mHeader->prev->next = mHeader->next;
    mHeader->next = itr.ptr;
    mHeader->prev = itr.ptr->prev;
    mHeader->next->prev = mHeader;
    mHeader->prev->next = mHeader;
}

void shift(int k) {
    if (k > 0) {
        k = k % mSize;
        update_list(k);
    } else if (k < 0) {
        while (k < 0) k += mSize;
        k = k % mSize;
        update_list(k);
    }
}
