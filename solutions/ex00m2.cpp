#include <iostream>
#include <utility>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int items[1000001];
priority_queue<pair<int, int> > pq[1000001];
map<pair<int, int>, int> mp;
vector<int> result[1000001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m, a;
    cin >> n >> m >> a;

    for (int i=1; i<=n; i++) {
        cin >> items[i];
    }

    while (a--) {
        char c;
        cin >> c;

        if (c=='W') {
            int u, i;
            cin >> u >> i;

            if (mp.find({u, i}) != mp.end()) mp.erase({u, i});
        } else {
            int u, i, v;
            cin >> u >> i >> v;

            mp[{u, i}] = v;
            pq[i].push({v, u});
        }
    }

    for (int i=1; i<=n; i++) {
        while (!pq[i].empty() && items[i]) {
            while (!pq[i].empty() && mp[{pq[i].top().second, i}] != pq[i].top().first) pq[i].pop();
            if (!pq[i].empty()) {
                result[pq[i].top().second].push_back(i);
                mp[{pq[i].top().second, i}] = 0;
                items[i]--;
                pq[i].pop();
            }
        }
    }

    for (int i=1; i<=m; i++) {
        if (result[i].empty()) {
            cout << "NONE\n";
        } else {
            for (int x: result[i]) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
