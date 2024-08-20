#include <iostream>
#include <vector>

using namespace std;

void vector_swap(
    vector<int> &v1,
    vector<int> &v2,
    int start1, int end1,
    int start2, int end2
) {
    vector<int> tmp_v1, tmp_v2;
    for (int i=0; i<v1.size(); i++) {
        if (!(start1<=i && i<end1) && start1!=i) {
            tmp_v1.push_back(v1[i]);
        } else {
            if (start1==i) {
                for (int j=start2; j<end2; j++) {
                    tmp_v1.push_back(v2[j]);
                }
            }
            if (start1==end1) tmp_v1.push_back(v1[i]);
        }
    }

    for (int i=0; i<v2.size(); i++) {
        if (!(start2<=i && i<end2) && start2!=i) {
            tmp_v2.push_back(v2[i]);
        } else {
            if (start2==i) {
                for (int j=start1; j<end1; j++) {
                    tmp_v2.push_back(v1[j]);
                }
            }
            if (start2==end2) tmp_v2.push_back(v2[i]);
        }
    }

    v1 = tmp_v1;
    v2 = tmp_v2;

    tmp_v1.clear(), tmp_v1.shrink_to_fit();
    tmp_v2.clear(), tmp_v2.shrink_to_fit();
}

int main() {
    //read input
    int n,c;
    vector<int>v1,v2;
    cin >> n; //number of v1
    for (int i = 0;i < n;i++) {
        cin >> c;
        v1.push_back(c);
    }
    cin >> n; //number of v2
    for (int i = 0;i < n;i++) {
        cin >> c;
        v2.push_back(c);
    }
    int s1,e1,s2,e2; //position
    cin >> s1 >> e1 >> s2 >> e2;
    //call the function
    vector_swap(v1,v2,s1,e1,s2,e2);
    //display content of the stack
    cout << "v1 has " << v1.size() << endl;
    for (auto &x : v1) { cout << x << " "; }
    cout << endl;
    //display content of the stack
    cout << "v2 has " << v2.size() << endl;
    for (auto &x : v2) { cout << x << " "; }
    cout << endl;
}
