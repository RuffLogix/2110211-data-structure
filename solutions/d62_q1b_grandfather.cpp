#include <iostream>
#include <map>

using namespace std;

map<string, string> parents;

string find_parent(string u, int depth) {
    if (depth==2) return u;
    if (parents.find(u) == parents.end()) return "";
    return find_parent(parents[u], depth+1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, t;
    cin >> n >> t;

    for (int i=1; i<=n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        parents[s2] = s1;
    }

    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        bool dup = s1 == s2;
        s1 = find_parent(s1, 0);
        s2 = find_parent(s2, 0);

        cout << (s1 == s2 && s1 != "" && !dup ? "YES" : "NO") << '\n';
    }

    return 0;
}
