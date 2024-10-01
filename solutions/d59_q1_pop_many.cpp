#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
    while (!empty() && K--) {
        pop();
    }
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
    std::stack<T> tmp1, tmp2;
    while (!empty() && K--) {
        tmp1.push(top());
        pop();
    }

    while(!tmp1.empty()) {
        tmp2.push(tmp1.top());
        tmp1.pop();
    }

    return tmp2;
}

#endif
