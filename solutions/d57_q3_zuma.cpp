#include <iostream>
#include <iterator>
#include <list>
#include <utility>

using namespace std;

list<int> l;

pair<list<int>::iterator, int> get_front(list<int>::iterator it) {
    auto temp = it;
    int cnt = 0;
    temp--;
    while (it != l.begin() && *temp == *it) {
        it--;
        temp--;
        cnt += 1;
    }
    return { it, cnt };
}

pair<list<int>::iterator, int> get_back(list<int>::iterator it) {
    auto temp = it;
    int cnt = 1;
    temp++;
    while (it != l.end() && *temp == *it) {
        it++;
        temp++;
        cnt += 1;
    }
    if (distance(it, l.end()) != 0) { it++, cnt++; }
    return { it, cnt };
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k, v;
    cin >> n >> k >> v;

    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        l.push_back(x);
    }

    auto insert_iter = l.begin();
    advance(insert_iter, k);
    l.insert(insert_iter, v);
    --insert_iter;

    auto iter1 = insert_iter;
    auto iter2 = insert_iter;

    while (iter1 != l.begin() && *(--iter1) == *insert_iter);
    while (iter2 != l.end() && *(++iter2) == *insert_iter);

    iter1++;
    // iter2--;

    if (distance(iter1, iter2) >= 3) {
        auto last_removed_iter = l.erase(iter1, iter2);

        auto info1 = get_front(last_removed_iter);
        auto info2 = get_back(last_removed_iter);

        while ((info1.second + info2.second - 1) >= 3 && info1.second) {
            last_removed_iter = l.erase(info1.first, info2.first);

            info1 = get_front(last_removed_iter);
            info2 = get_back(last_removed_iter);
        }
    }

    for (int x: l) {
        cout << x << ' ';
    }

    return 0;
}
