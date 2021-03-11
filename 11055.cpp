#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int dp[1001];
	int sol[1001] = { 0, };
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		dp[i] = k;
	}
	sol[0] = dp[0];
	for (int i = 1; i < n; i++) {
		sol[i] = dp[i];
		for (int j = 0; j <= i; j++) {
			if (dp[i] > dp[j]) {
				sol[i] = max(sol[i], sol[j] + dp[i]);
			}
		}
	}

	int solve = sol[0];
	for (int i = 0; i < n; i++) {
		if (solve < sol[i]) {
			solve = sol[i];
		}
	}

	cout << solve << endl;
}