#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001];
int sol[1001] = { 1, };

int main() {
	int n,k,sum;
	sum = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		dp[i] = k;
	}

	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < i; j++) {
			if (dp[j] < dp[i]) {				
				sum = max(sol[j], sum);				
			
			}
			sol[i] =  sum + 1;
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