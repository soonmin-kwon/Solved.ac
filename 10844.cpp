#include<iostream>
using namespace std;

int stair[101][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ans = 0;
	cin >> n;

	for (int i = 1; i < 10; i++) {
		stair[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				stair[i][j] = stair[i - 1][1];
				continue;
			}
			if (j == 9) {
				stair[i][j] = stair[i - 1][8];
				continue;
			}
			stair[i][j] = (stair[i - 1][j - 1] + stair[i - 1][j + 1]) % 1000000000;
		}
	}

	for (int i = 0; i < 10; i++) {
		ans = (ans + stair[n][i]) % 1000000000;
	}
	cout << ans << "\n";
}