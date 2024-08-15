#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int q;
    cin >> q;

    vector<int> v;

    while (q--) {
        string opt;
        cin >> opt;

        if (opt == "pb") {
            int x;
            cin >> x;

            v.push_back(x);
        } else if (opt == "sa") {
            sort(v.begin(), v.end());
        } else if (opt == "sd") {
            sort(v.begin(), v.end(), greater<int>());
        } else if (opt == "r") {
            reverse(v.begin(), v.end());
        } else if (opt == "d") {
            int i;
            cin >> i;

            v.erase(v.begin() + i);
        }
    }

    for (int x: v) {
        cout << x << ' ';
    }

    return 0;
}
