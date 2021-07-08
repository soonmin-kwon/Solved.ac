#include<iostream>
using namespace std;

int ascent[1001][11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ans = 0;
	cin >> n;

	for (int i = 0; i < 10; i++) {
		ascent[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				ascent[i][j] += ascent[i - 1][k];
				ascent[i][j] %= 10007;
			}
		}		
	}

	for (int i = 0; i < 10; i++) {
		ans += ascent[n][i];
		ans %= 10007;
	}
	cout << ans;
}