#include <iostream>
#include <map>

using namespace std;

map<string, int> mp;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        mp[s] += 1;
    }

    for (pair<string, int> row: mp) {
        if (row.second>1) {
            cout << row.first << ' ' << row.second << '\n';
        }
    }

    return 0;
}
