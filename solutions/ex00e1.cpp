#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int h, m;
    cin >> h >> m;

    int x;
    cin >> x;

    h += ((m+x) / 60);
    h %= 24;
    m = (m+x) % 60;

    string hh = (h<=9 ? '0' + to_string(h) : to_string(h));
    string mm = (m<=9 ? '0' + to_string(m) : to_string(m));

    cout << hh << ' ' << mm << '\n';

    return 0;
}
