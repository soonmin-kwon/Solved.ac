#include<iostream>
#include<algorithm>
using namespace std;

int dp[501][501];
int dp2[501][501];

int main() {
	
	int n , k, solve;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> k;
			dp[i][j] = k;
		}
	}
	dp2[0][0] = dp[0][0];	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp2[i][j] = dp2[i - 1][j] + dp[i][j];
			}
			else if (j == i) {
				dp2[i][j] = dp2[i - 1][j-1] + dp[i][j];
			}
			else {
				dp2[i][j] = max(dp2[i - 1][j - 1], dp2[i - 1][j ]) + dp[i][j];
			}
			
		}
	}
	solve = dp2[n][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp2[i][j] >= solve) {
				solve = dp2[i][j];
			}
		}
	}
	cout << solve;
}