#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001];
int sol[1001] = { 1, };

int main() {

	int n , k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		dp[i] = k;
	}

	for (int i = 1; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < i; j++) {
			if (dp[i] > dp[j]) {
				sum = max(sum, sol[j]);
			}
		}
		sol[i] = sum + 1;		
	}

	int temp = sol[0];
	for (int i = 1; i < n; i++) {
		if (temp < sol[i]) {
			temp = sol[i];
		}
	}
	cout << temp << endl;
}