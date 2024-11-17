// You may include library here

int depth_aux(node *n) {
    if (n == NULL) return 0;
    int ans = 0;
    if (n->left_child != NULL) ans = max(ans, depth_aux(n->left_child) + 1);
    if (n->right_sibling != NULL) ans = max(ans, depth_aux(n->right_sibling));
    return ans;
}

int depth(node *n) {
    if (n == NULL) return -1;
    return depth_aux(n);
}
