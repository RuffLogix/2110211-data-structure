#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    set<int> s;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    set<int> ans;
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        if (s.find(x) != s.end()) {
            ans.insert(x);
        }
    }

    for (int x: ans) {
        cout << x << ' ';
    }

    return 0;
}
