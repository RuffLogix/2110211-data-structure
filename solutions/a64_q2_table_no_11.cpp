#include <iostream>

using namespace std;

int dp[10000001][2][2];

int solve(int n, bool up, bool down) {
    if (n==1) return  !(up && down);
    if (dp[n][up][down]) return dp[n][up][down];

    if (up && !down) return dp[n][up][down] = solve(n-1, false, false) + solve(n-1, false, true) % int(1e8+7);
    if (!up && down) return dp[n][up][down] = solve(n-1, false, false) + solve(n-1, true, false) % int(1e8+7);;

    return dp[n][up][down] = (solve(n-1, false, false) % int(1e8+7) + solve(n-1, false, true) % int(1e8+7) + solve(n-1, true, false) % int(1e8+7)) % int(1e8+7);;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    cout << solve(n+1, false, false);

    return 0;
}
