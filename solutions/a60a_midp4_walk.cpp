#include <iostream>

using namespace std;

int arr[501][501];
int dp[501][501];

int solve(int i, int j) {
    if (i<=0 || j<=0) return -1e9;
    if (i==1 && j==1) return arr[i][j];
    if (dp[i][j]) return dp[i][j];

    return dp[i][j] = max(solve(i, j-1) + arr[i][j], max(solve(i-1, j) + arr[i][j], solve(i-1, j-1) + 2*arr[i][j]));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << solve(n, m) << '\n';

    return 0;
}
