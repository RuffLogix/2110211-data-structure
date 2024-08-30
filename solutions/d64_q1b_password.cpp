#include <iostream>
#include <set>

using namespace std;

int encrypted_key[51];
set<string> passwords;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m, l;
    cin >> n >> m >> l;

    for (int i=1; i<=l; i++) {
        cin >> encrypted_key[i];
    }

    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        passwords.insert(s);
    }

    while (m--) {
        string s;
        cin >> s;

        for (int i=1; i<=s.size(); i++) {
            s[i-1] = char(((s[i-1] - 'a' + encrypted_key[i]) % 26) + 'a');
        }

        if (passwords.find(s)!=passwords.end()) {
            cout << "Match\n";
        } else {
            cout << "Unknown\n";
        }
    }

    return 0;
}
