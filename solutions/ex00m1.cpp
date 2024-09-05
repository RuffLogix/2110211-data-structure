#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int chefs[1000001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for (int i=1; i<=n; i++) {
        cin >> chefs[i];
        pq.push({0, i});
    }

    int ans=0;
    int cur=0;
    while (true) {
        if (m<=0) break;
        while (!pq.empty() && pq.top().first==cur && m--) {
            cout << cur << '\n';
            pq.push({cur + chefs[pq.top().second], pq.top().second});
            pq.pop();
        }

        cur = pq.top().first;
    }

    return 0;
}
