#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cmath>
#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
    if (size() == 0) return -1;
    return std::log2(size());
}

#endif
