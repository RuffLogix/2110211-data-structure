#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

pair<int, int> interval[200001];
int a[200001], b[200001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        cin >> interval[i].first >> interval[i].second;
    }

    sort(interval+1, interval+1+n);

    for (int i=1; i<=n; i++) {
        a[i] = interval[i].first;
        b[i] = interval[i].second;
    }

    while (m--) {
        int x;
        cin >> x;

        int index = upper_bound(a+1, a+1+n, x) - a;
        if (a[index-1]<=x && x<=b[index-1]) {
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }

    return 0;
}
