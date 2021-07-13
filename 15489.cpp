#include<iostream>
using namespace std;

int dp[31][31];
int r, c, w, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> w;

	dp[1][1] = 1;

	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i) {
				dp[i][j] = 1;
			}			
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
	}


	for (int i = 0; i < w; i++) {
		for (int j = 0; j <= i; j++) {
			ans += dp[r + i][c + j];
		}
	}

	cout << ans;
}