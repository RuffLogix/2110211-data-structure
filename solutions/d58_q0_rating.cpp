#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

map<string, int> subjects, prof;
map<string, int> n_subjects, n_prof;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        string s, p;
        int score;
        cin >> s >> p >> score;
        subjects[s] += score, n_subjects[s] += 1;
        prof[p] += score, n_prof[p] += 1;
    }

    for (pair<string, int> row: subjects) {
        string subject = row.first;
        float avg_score = (1.0 * subjects[subject]) / (1.0 * n_subjects[subject]);
        cout << subject << ' ' << fixed << setprecision(2) << avg_score << '\n';
    }

    for (pair<string, int> row: prof) {
        string pro = row.first;
        float avg_score = (1.0 * prof[pro]) / (1.0 * n_prof[pro]);
        cout << pro << ' ' << fixed << setprecision(2) << avg_score << '\n';
    }

    return 0;
}
