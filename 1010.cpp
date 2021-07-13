#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m;
    int sol[31][31];
    sol[1][2] = 2;
    cin >> t;
    for (int i = 0; i < t; i++) {

        cin >> n; cin >> m;

        for (int i = 1; i <= m; i++) {
            sol[0][i] = 1;
        }

        for (int i = 1; i <= m; i++) {
            sol[i][i] = 1;
        }

        for (int f = 3; f <= 31; f++) {
            for (int s = 1; s < f; s++) {
                sol[s][f] = sol[s][f - 1] + sol[s - 1][f - 1];
            }
        }
        cout << sol[n][m] << "\n";
    }
}