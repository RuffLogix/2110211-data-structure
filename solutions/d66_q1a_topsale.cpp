#include <iostream>
#include <set>
#include <utility>
#include <map>

using namespace std;

map<int, int> item;
set<int> item_id;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    set<pair<int, int> > s;

    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        item_id.insert(x);
    }

    while (m--) {
        int opt;
        cin >> opt;

        if (opt == 1) {
            int a, b;
            cin >> a >> b;
            if (item_id.find(a) == item_id.end()) {
                continue;
            }
            if (s.find({item[a], a}) != s.end()) s.erase({item[a], a});
            item[a] += b;
            s.insert({item[a], a});
        } else {
            int k;
            cin >> k;

            if (s.lower_bound({k, 0}) != s.begin()) {
                auto id_itr = s.lower_bound({k, 0});
                id_itr--;
                int id = id_itr->second;
                cout << id << '\n';
            } else {
                cout << "NONE\n";
            }
        }
    }

    return 0;
}
