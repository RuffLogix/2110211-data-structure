#include <iostream>

using namespace std;

int a, b, c;
int dp[4001];

int solve(int n) {
    if (n < 0) return -1e9;
    if (n == 0) return 0;
    if (dp[n]) return dp[n];

    return dp[n] = max(solve(n-a), max(solve(n-b), solve(n-c))) + 1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n >> a >> b >> c;

    cout << solve(n) << '\n';

    return 0;
}
