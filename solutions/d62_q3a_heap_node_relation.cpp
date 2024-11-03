#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        if (a == b) {
            cout << "a and b are the same node\n";
        } else {
            bool a_less_than_b = a < b;
            if (!a_less_than_b) swap(a, b);

            while (a < b) {
                b = (b-1)/2;
            }

            if (a == b && a_less_than_b) {
                cout << "a is an ancestor of b\n";
            } else if (a == b && !a_less_than_b) {
                cout << "b is an ancestor of a\n";
            } else {
                cout << "a and b are not related\n";
            }
        }
    }

    return 0;
}
