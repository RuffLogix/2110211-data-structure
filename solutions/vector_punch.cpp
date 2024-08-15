#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<string> punch(vector<string> &v, vector<string>::iterator it,int k) {
    int index = it - v.begin();
    vector<string> ans;
    for (int i=0; i<v.size(); i++) {
        if (abs(i-index)>k) {
            ans.push_back(v[i]);
        }
    }
    return ans;
}

int main() {
    int n,j,k;
    cin >> n >> j >> k;
    vector<string> v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result) {
        cout << x << endl;
    }
}
