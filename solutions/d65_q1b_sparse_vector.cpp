#include <iostream>
#include <random>
#include <vector>
#include <utility>
#include <map>

using namespace std;

void insert_into_sv(map<int, int>& v, int pos, int value) {
    auto iter = v.lower_bound(pos);
    vector<pair<int, int> > tmp(iter, v.end());
    v.erase(iter, v.end());
    v[pos] = value;
    for (pair<int, int> &p: tmp) {
        v.insert(v.end(), {p.first + 1, p.second});
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    map<int,int> v;
    cin >> n;
    for (int i = 0;i < n;i++) {
        int a,b;
        cin >> a >> b;
        insert_into_sv(v,a,b);
    }
    cout << v.size() << "\n";
    for (auto &x : v) {
        cout << x.first << ": " << x.second << "\n";
    }
}
