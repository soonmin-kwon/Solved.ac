#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n,k;
	cin >> n;
	int dp[1001];
	int sol[1001] = { 1, };
	for (int i = 0; i < n; i++) {
		cin >> k;
		dp[i] = k;
	}

	for (int i = 1; i < n; i++) {
		int sum = 0;
		for (int j = 0; j <= i; j++) {
			if (dp[i] < dp[j]) {
				sum = max(sum, sol[j]);
			}
		}
		sol[i] = sum + 1;
	}
	int solve = sol[0];
	for (int i = 0; i < n; i++) {
		if (sol[i] > solve) {
			solve = sol[i];
		}
	}

	cout << solve;
}