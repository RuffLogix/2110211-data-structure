#ifndef __STUDENT_Hx
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename KeyT,
          typename MappedT,
          typename HasherT,
          typename EqualT>
size_t CP::unordered_map<KeyT,MappedT,HasherT,EqualT>::max_bucket_length() {
    size_t res = 0;
    for (auto bucket: mBuckets) {
        res = std::max(res, bucket.size());
    }
    return res;
}

#endif
