#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void list_erase(vector<int> &v, vector<int> &pos) {
    vector<int> tmp;
    sort(pos.begin(), pos.end());
    for (int i=0; i<v.size(); i++) {
        if (!binary_search(pos.begin(), pos.end(), i)) {
            tmp.push_back(v.at(i));
        }
    }
    v = tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n), pos(m);
    for (int i = 0;i < n;i++) cin >> v[i];
    for (int i = 0;i < m;i++) cin >> pos[i];
    list_erase(v,pos);
    cout << "After call list_erase" << endl << "Size = " << v.size() << endl;
    for (auto &x : v) cout << x << " ";
    cout << endl;
}
