#include <iostream>

using namespace std;

int tree[1000001], arr[1000001];

void update(int index, int value) {
    for (; index<=1000000; index += index&-index) {
        tree[index] += value;
    }
}

int search(int value) {
    int sum = 0;
    int position = 0;

    for (int i=20; i>=0; i--) {
        if (position + (1 << i) <= 1000000 && tree[position + (1 << i)] + sum < value) {
            position += (1 << i);
            sum += tree[position];
        }
    }

    return position + 1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i=1; i<=n; i++) {
        cin >> arr[i];
        update(arr[i], 1);
        if (i>=k+1) {
            if (arr[i-k-1] != 0)update(arr[i-k-1], -1);
            cout << search(k/2+1) << ' ';
        }
    }

    return 0;
}
