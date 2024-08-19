#include <iostream>
#include <map>

using namespace std;

map<int, int> mp;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, t;
    cin >> n >> t;

    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        mp[x] += 1;
    }

    while (t--) {
        int x;
        cin >> x;

        bool ans=false;
        for (pair<int, int> m: mp) {
            if (mp.find(x-m.first) != mp.end() && m.first*2 != x) {
                ans |= true;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}
