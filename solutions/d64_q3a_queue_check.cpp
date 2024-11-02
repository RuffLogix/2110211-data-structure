#include <iostream>

using namespace std;

bool check_queue(int mFront, int mSize, int mCap, int last) {
    return mFront < mCap && last <= mCap && mSize <= mCap && (mFront + mSize) % mCap == last;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int mFront, mSize, mCap, last, correction;
        cin >> mFront >> mSize >> mCap >> last >> correction;

        if (check_queue(mFront, mSize, mCap, last)) {
            cout << "OK\n";
        } else{
            cout << "WRONG ";

            switch (correction) {
                case 1:
                    cout << (last - mSize + mCap) % mCap;
                    break;
                case 2:
                    cout << (last - mFront + mCap) % mCap;
                    break;
                case 3:
                    if (last > mFront) cout << last + 1;
                    else cout << mFront + (mSize - last);
                    break;
                case 4:
                    cout << (mFront + mSize) % mCap;
                    break;
            }

            cout << '\n';
        }
    }

    return 0;
}

/*
10
0 0 1 0 0
0 2 4 2 0
0 8 8 20 0
0 2 4 0 0
0 2 4 0 2
0 2 4 0 4
1 3 8 7 1
10 100 8 110 3
3 8 2 3 3
3 2 0 5 3
*/
