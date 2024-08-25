#include <iostream>

using namespace std;

int n;
int trig[101][101];
int dp[101][101];

int solve(int i, int j) {
    if (i<=0 || j<=0 || j>i || i>n) return 0;
    if (dp[i][j]) return dp[i][j];

    return dp[i][j] = max(solve(i+1, j), solve(i+1, j+1)) + trig[i][j];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            cin >> trig[i][j];
        }
    }

    cout << solve(1, 1) << '\n';

    return 0;
}
