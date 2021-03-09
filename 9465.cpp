#include<iostream>
#include<algorithm>
using namespace std;
int dp[2][100001];
int ans[2][100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n , k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		
		cin >> n;
		for (int j = 0; j < 2; j++) {
			for (int c = 1; c <= n; c++) {
				cin >> k;
				dp[j][c] = k;
			}
		}
		ans[0][0] = ans[1][0] = 0;
		ans[0][1] = dp[0][1]; ans[1][1] = dp[1][1];		
		for (int i = 2; i <= n; i++) {
			ans[0][i] = max(ans[1][i - 1], ans[1][i - 2]) + dp[0][i];
			ans[1][i] = max(ans[0][i - 1], ans[0][i - 2]) + dp[1][i];
			
		}

		cout << max(ans[0][n], ans[1][n]) << endl;
	}
	
}