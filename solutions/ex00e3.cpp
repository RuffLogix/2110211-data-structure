#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    set<int> s;
    int sum = (1+n)*n/2;

    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (s.find(x)==s.end()) {
            sum -= x;
        }
        s.insert(x);
    }

    cout << (s.size()!=n || sum!=0 ? "NO\n" : "YES\n");

    return 0;
}
