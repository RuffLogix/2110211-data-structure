#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
   if (m<=0 || a<begin() || b<begin() || a+m-1>=end() || b+m-1>=end()) return false;
   if ((a<=b && a+m-1>=b) || (b<=a && b+m-1>=a)) return false;

   for (int i=0; i<m; i++) {
       int tmp = a[i];
       a[i] = b[i];
       b[i] = tmp;
   }

   return true;
}

#endif
