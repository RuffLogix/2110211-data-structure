#include <iostream>

using namespace std;

bool check[500001];
int cnt = 0;

void solve(int n, int m) {
    if (n <= m) return;

    cnt += 1;
    check[m] = true;

    solve(n, m*2+1);
    solve(n, m*2+2);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    solve(n, m);

    cout << n - cnt << '\n';

    for (int i=0; i<n; i++) {
        if (!check[i]) cout << i << ' ';
    }

    return 0;
}
