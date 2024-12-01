#include <iostream>
#include <utility>

using namespace std;

int n, m;
pair<int, int> arr[2001];

int hash_function(int x) {
    return x % n;
}

int get_insert_count(int x, int col) {
    int index = col == 0 ? x : x + 2*col - 1;
    int hashed_index = hash_function(index);
    return ((arr[hashed_index].second < 2) ? 0 : get_insert_count(hashed_index, col+1)) + 1;
}

int get_search_count(int x, int col) {
    int index = col == 0 ? x : x + 2*col - 1;
    int hashed_index = hash_function(index);
    return ((arr[hashed_index].second == 0) ? 0 : get_search_count(hashed_index, col+1)) + 1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;

        int col = 1;
        int cnt = 0;
        int temp_b = b;
        b = hash_function(b);

        if (a == 1) {
            // Case 1: Insertion
            while (arr[b].second == 2) {
                b = hash_function(b + 2*col - 1);
                col += 1;
            }
            arr[b] = make_pair(temp_b, 2);
        } else if (a == 2) {
            // Case 2: Deletion
            while (!(arr[b].first == temp_b && arr[b].second == 2) && cnt < n) {
                b = hash_function(b + 2*col - 1);
                cnt += 1;
                col += 1;
            }
            if (cnt < n) arr[b].second = 1;
        }
    }

    int a1 = 0;
    for (int i=0; i<n; i++) a1 = max(a1, get_insert_count(i, 0));
    int a2 = 0;
    for (int i=0; i<n; i++) a2 = max(a2, get_search_count(i, 0));

    cout << a1 << ' ' << a2 << '\n';

    return 0;
}
