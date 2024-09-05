#include <algorithm>
#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

int qs[40001];
pair<int, int> day_money[40001];
int days[40001];
int moneys[40001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m, start;
    cin >> n >> m >> start;

    day_money[0].second = start;
    for (int i=1; i<=n; i++) {
        cin >> day_money[i].first >> day_money[i].second;
    }

    sort(day_money, day_money+n+1);

    for (int i=0; i<=n; i++) {
        days[i] = day_money[i].first;
        moneys[i] = day_money[i].second;
        if (i!=0) qs[i] = qs[i-1] + moneys[i-1] * (days[i] - days[i-1]);
    }

    for (int i=1; i<=m; i++) {
        int p, x;
        cin >> p >> x;

        int index = upper_bound(days, days+1+n, x) - days - 1;

        if (qs[index] + moneys[index] * (x - days[index] + 1) >= p) {
            int index_money = upper_bound(qs, qs+1+n, p) - qs - 1;
            cout << days[index_money] + ceil(1.0 * (p-qs[index_money]) / moneys[index_money]) - 1 << ' ';
        } else {
            int index_money = upper_bound(qs, qs+1+n, qs[index] + moneys[index] * (x - days[index] + 1) + p) - qs - 1;
            cout << days[index_money] + ceil(1.0 * (qs[index] + moneys[index] * (x - days[index] + 1) + p - qs[index_money]) / moneys[index_money]) - 1 << ' ';
        }
    }

    return 0;
}
