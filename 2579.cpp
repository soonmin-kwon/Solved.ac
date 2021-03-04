#include<iostream>
#include<algorithm>
using namespace std;

int dp[301];
int cost[301];

int main() {
	int n;
	cin >> n;
	int c;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		cost[i] = c;
	}

	dp[1] = cost[1];
	dp[2] = max(cost[2], cost[1] + cost[2]);
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + cost[i], dp[i - 3] + cost[i - 1] + cost[i]);
	}
	
	cout << dp[n];
}