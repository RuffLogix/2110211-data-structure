#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    long long mCap = 1, mSize = 0;

    for (int i=1; i<=n; i++) {
      int x, c;
      cin >> x >> c;

      if (x==0) {
        mSize += c;
      } else {
        mSize -= c;
      }

      while (mSize > mCap) mCap *= 2;
    }

    cout << mCap - mSize << '\n';

    return 0;
}
