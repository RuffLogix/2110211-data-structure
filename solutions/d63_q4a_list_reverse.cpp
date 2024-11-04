#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
    iterator temp_itr = a;
    iterator ans = a;
    std::vector<T> temp_value;
    while (temp_itr != b) {
        temp_value.push_back(*temp_itr);
        temp_itr++;
    }
    while (a != b) {
        *a = temp_value.back();
        temp_value.pop_back();
        a++;
    }
    return ans;
}

#endif
