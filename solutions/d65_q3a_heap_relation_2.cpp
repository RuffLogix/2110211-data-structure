#include <cmath>
#include <iostream>

using namespace std;

bool is_des(long long s, long long a, long long b) {
    if (a == b) return false;
    if (b < a) swap(a, b);
    while (a < b) {
        b = (b-1) / s;
    }
    return a == b;
}

int get_height(long long s, long long h) {
    if (h == 0) return 0;
    return get_height(s, (h-1) / s) + 1;
}

bool same_level(long long s, long long a, long long b) {
    int level_a = get_height(s, a);
    int level_b = get_height(s, b);
    return level_a == level_b;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        long long s, a, b;
        cin >> s >> a >> b;

        if ((a-1)/s == b || (b-1)/s == a) cout << 1;
        else if (is_des(s, a, b)) cout << 2;
        else if (!same_level(s, a, b)) cout << 3;
        else cout << 4;

        cout << ' ';
    }

    return 0;
}
