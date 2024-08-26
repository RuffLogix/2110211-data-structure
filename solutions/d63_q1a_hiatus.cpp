#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int publish_date[200001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        int year, month;
        cin >> year >> month;
        publish_date[i] = year*100 + month;
    }

    sort(publish_date+1, publish_date+1+n);

    while (m--) {
        int year, month;
        cin >> year >> month;

        int index = upper_bound(publish_date+1, publish_date+1+n, year*100 + month) - publish_date;

        if (index == 1) {
            cout << "-1 -1 ";
        } else {
            int p_year = publish_date[index-1]/100;
            int p_month = publish_date[index-1]%100;

            if (p_year==year && p_month==month) {
                cout << "0 0 ";
            } else {
                cout << p_year << ' ' << p_month << ' ';
            }
        }
    }

    return 0;
}
