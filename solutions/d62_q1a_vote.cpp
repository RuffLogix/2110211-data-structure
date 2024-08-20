#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<string, int> mp;
vector<int> votes;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        mp[s] += 1;
    }

    for (pair<string, int> row: mp) {
        votes.push_back(row.second);
    }

    sort(votes.begin(), votes.end(), greater<int>());

    int ans=1e9;
    for (int i=0; i<votes.size(); i++) {
        if (i<k || votes[i]==votes[k-1]) {
            ans = votes[i];
        }
    }

    cout << ans << '\n';

    return 0;
}
