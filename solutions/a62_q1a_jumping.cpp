#include <iostream>

using namespace std;

int arr[1000001];
int dp[1000001];

int solve(int n) {
    if (n<=0) return -1e9;
    if (n==1) return arr[n];
    if (dp[n]) return dp[n];

    return dp[n] = max(solve(n-1), max(solve(n-2), solve(n-3))) + arr[n];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    cout << solve(n) << '\n';

    return 0;
}
