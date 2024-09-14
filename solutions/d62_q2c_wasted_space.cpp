#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    int logn = ceil(log2(n));
    int remained_memories = pow(2, logn) - n;

    cout << remained_memories << '\n';


    return 0;
}
