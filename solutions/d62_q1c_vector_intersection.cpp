#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> v1, v2;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        v1.push_back(x);
    }

    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        v2.push_back(x);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    size_t i=0, j=0;
    vector<int> ans;
    while (i<v1.size() && j<v2.size()) {
        if (v1[i]==v2[j]) {
            ans.push_back(v1[i]);
            i++, j++;
        } else if(v1[i]>v2[j]) {
            j++;
        } else {
            i++;
        }
    }

    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

    for (int x: ans) {
        cout << x << ' ';
    }

    return 0;
}
