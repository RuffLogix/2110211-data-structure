#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT,MappedT,CompareT>::my_recur(node* n,int level,int tmp) {
    if (n == NULL) return;
    my_recur(n->left, level+1, tmp);
    my_recur(n->right, level+1, tmp);
    if (level > tmp) erase(n->data.first);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT,MappedT,CompareT>::trim(int depth) {
	/*write your code here
    If you cry on seeing the question, it is an insult.
    If your teacher cries upon seeing your answer submission,
    it is your achievement.

    Good luck with final and see you in Algorithm Design.
    */
    my_recur(mRoot, 0, depth);
}

#endif
