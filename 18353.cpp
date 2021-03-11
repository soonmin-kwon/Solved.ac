#include<iostream>
#include<algorithm>
using namespace std;

int sol[2001];
int dp[2001];

int main() {

	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		dp[i] = k;
	}	
	int ans = n;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (dp[i] < dp[j]) {
				sol[i] = max(sol[j]+1, sol[i]);
			}
			ans = min(ans, n - sol[i] - 1);
		}
	}
	
	if (ans == n) {
		cout << 0 << endl;
	}
	else {
		cout << ans << endl;
	}
	
}