#include <iostream>

using namespace std;

int qs[1001][1001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> qs[i][j];
            qs[i][j] += qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
        }
    }

    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1++;
        y1++;
        x2++;
        y2++;

        int ans = qs[x2][y2] - qs[x2][y1-1] - qs[x1-1][y2] + qs[x1-1][y1-1];

        cout << ans << '\n';
    }

    return 0;
}
