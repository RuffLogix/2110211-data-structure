#include <vector>
#include <map>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    map<T, bool> check;
    for (int x: A) {
        if (check.find(x) == check.end()) {
            v.push_back(x);
            check[x] = true;
        }
    }
    for (int x: B) {
        if (check.find(x) == check.end()) {
            v.push_back(x);
            check[x] = true;
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    map<T, bool> check;
    for (int x: A) {
        if (check.find(x) == check.end()) {
            check[x] = true;
        }
    }
    for (int x: B) {
        if (check.find(x) != check.end()) {
            check[x] = false;
        }
    }
    for (int x: A) {
        if (check.find(x) != check.end() && !check[x]) {
            v.push_back(x);
            check.erase(x);
        }
    }
    for (int x: B) {
        if (check.find(x) != check.end() && !check[x]) {
            v.push_back(x);
            check.erase(x);
        }
    }
    return v;
}
