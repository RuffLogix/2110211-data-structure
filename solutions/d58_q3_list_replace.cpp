void replace(const T& x, list<T>& y) {
    auto itr = begin();

    while (itr!=end()) {
        if (*itr == x) {
            itr = erase(itr);
            for (auto x: y) {
                itr = insert(itr, x);
                itr++;
            }
        } else {
            itr++;
        }
    }
}
