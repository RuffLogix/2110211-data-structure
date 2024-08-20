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

    string ans_s = "";
    int ans_c = 0;
    for (map<string, int>::iterator it=mp.begin(); it!=mp.end(); it++) {
        if (it->second>=ans_c) {
            ans_s = it->first;
            ans_c = it->second;
        }
    }

    cout << ans_s << ' ' << ans_c << '\n';

    return 0;
}
