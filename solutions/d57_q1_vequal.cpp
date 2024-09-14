#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator==(const vector<T> &other) const {
    if (size() != other.size()) return false;
    for (int i=0; i<size(); i++) {
        if (at(i) != other.at(i)) {
            return false;
        }
    }
    return true;
}

#endif
