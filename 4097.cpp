#include<iostream>
#include<algorithm>
using namespace std;

int dp[250000];


int main() {
	int n,k;

	while (true) {
		cin >> n;
		int solve = -10001;
		int sum = 0;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> k;
			sum += k;
			solve = max(solve, sum);
			sum = max(sum, 0);
		}		
		cout << solve << endl;
	}
}