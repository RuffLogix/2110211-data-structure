#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct Character {
    int power, type;

    Character() { }
    Character(int power, int type): power(power), type(type) { }
};

Character characters[500001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++) cin >> characters[i].power;
    for (int i=1; i<=n; i++) cin >> characters[i].type;

    priority_queue<int> types[m];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for (int i=0; i<m; i++) {
        types[i].push(1);
        pq.push({1, i});
    }

    for (int i=1; i<=n; i++) {
        types[characters[i].type].push(characters[i].power);
        pq.push({characters[i].power, characters[i].type});

        while (!pq.empty() && types[pq.top().second].top()!=pq.top().first) pq.pop();

        cout << pq.top().first << ' ';
    }

    return 0;
}
