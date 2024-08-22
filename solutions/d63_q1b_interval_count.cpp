#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    while (m--) {
        int x;
        cin >> x;

        int start = lower_bound(v.begin(), v.end(), x-k) - v.begin();
        int end = upper_bound(v.begin(), v.end(), x+k) - v.begin();

        cout << end - start << ' ';
    }

    return 0;
}
