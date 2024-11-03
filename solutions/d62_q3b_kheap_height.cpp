#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    long long n, k;
    cin >> n >> k;

    long long k_div = 1;
    long long height = k == 1 ? n : 0;

    while (n > 0 && k != 1) {
        n -= k_div;
        height += 1;
        k_div *= k;
    }

    cout << height - 1 << '\n';

    return 0;
}
