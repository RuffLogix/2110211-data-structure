#include <iostream>
#include <map>
#include <utility>

using namespace std;

map<pair<string, string>, bool> mp;
string s1[1000001], s2[1000001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        mp[{s1, s2}] = false;
    }

    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;

        bool approved = true;
        for (int j=0; j<x; j++) {
            cin >> s1[j] >> s2[j];
            if (mp.find({s1[j], s2[j]}) == mp.end()) {
                approved = false;
            } else if (mp[{s1[j], s2[j]}] == true) {
                approved = false;
            }
        }

        if (approved) {
            for (int j=0; j<x; j++) {
                mp[{s1[j], s2[j]}] = true;
            }
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
