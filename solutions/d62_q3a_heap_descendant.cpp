#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> des;

void solve(int m, int n) {
    if (m >= n) return;

    des.push_back(m);

    solve(m*2 + 1, n);
    solve(m*2 + 2, n);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    solve(m, n);
    sort(des.begin(), des.end());

    cout << des.size() << '\n';
    for (int x: des) {
        cout << x << ' ';
    }

    return 0;
}
