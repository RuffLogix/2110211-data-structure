#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    multiset<int> s;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    int score=1;
    bool losed=false;
    while (m--) {
        int n_cards;
        cin >> n_cards;

        for (int i=0; i<n_cards; i++) {
            int x;
            cin >> x;
            if (s.upper_bound(x) != s.end()) {
                s.erase(s.upper_bound(x));
            } else {
                losed = true;
            }
        }

        if (!losed) score += 1;
    }

    cout << score << '\n';

    return 0;
}
