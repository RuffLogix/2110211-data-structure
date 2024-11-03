#include <iostream>

using namespace std;

int arr[50001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        bool ans = true;
        for (int i=0; i<n; i++) {
            cin >> arr[i];
            if (i != 0 && arr[i] > arr[(i-1)/k]) {
                ans = false;
            }
        }

        cout << (ans ? "true" : "false") << '\n';
    }

    return 0;
}
