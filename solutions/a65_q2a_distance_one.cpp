#include <iostream>

using namespace std;

int dp[5001];

int solve(int n, int k) {
    if (n<=0) return 1;
    if (dp[n]) return dp[n];

    return dp[n] = (solve(n-1, k) + solve(n-k, k)) % int(1e8+7);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;

    cout << solve(n, k) << '\n';

    return 0;
}
