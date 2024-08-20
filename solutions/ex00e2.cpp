#include <climits>
#include <iostream>

using namespace std;

int n, m;
int arr[101][101];

bool is_valid(int x1, int y1, int x2, int y2) {
    if (x1>x2 || y1>y2) {
        cout << "INVALID\n";
        return false;
    } else if (x1>n || x2<1 || y1>m || y2<1) {
        cout << "OUTSIDE\n";
        return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;

    int q;
    cin >> q;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> arr[i][j];
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (is_valid(x1, y1, x2, y2)) {
            int ans=INT_MIN;
            for (int i=max(1, x1); i<=min(n, x2); i++) {
                for (int j=max(1, y1); j<=min(m, y2); j++) {
                    ans = max(ans, arr[i][j]);
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
