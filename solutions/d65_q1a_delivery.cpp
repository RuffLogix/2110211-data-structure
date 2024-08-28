#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int p[100001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    queue<int> pq1, pq2;

    for (int i=1; i<=m; i++) {
        cin >> p[i];
    }

    vector<int> acc_p(1);

    while (n--) {
        int opt;
        cin >> opt;

        if (opt==1) {
            int a, b;
            cin >> a >> b;

            (a==1) ? pq1.push(b) : pq2.push(b);
        } else {
            if (pq1.empty()) {
                acc_p.push_back(acc_p.back() + pq2.front());
                pq2.pop();
            } else if (pq2.empty()) {
                acc_p.push_back(acc_p.back() + pq1.front());
                pq1.pop();
            } else {
                if (pq1.front() <= pq2.front()) {
                    acc_p.push_back(acc_p.back() + pq1.front());
                    pq1.pop();
                } else {
                    acc_p.push_back(acc_p.back() + pq2.front());
                    pq2.pop();
                }
            }
        }
    }

    for (int i=1; i<=m; i++) {
        int index = lower_bound(acc_p.begin(), acc_p.end(), p[i]) - acc_p.begin();

        cout << (index != acc_p.size() ? index : -1) << ' ';
    }

    return 0;
}
