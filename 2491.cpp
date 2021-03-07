#include<iostream>
#include<algorithm>
using namespace std;

int bigger[100001] = { 1, };
int smaller[100001] = { 1, };
int dp[100001];

int main() {
	int n,k;
	int big=1, small=1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k ;
		dp[i] = k;
	}

	for (int i = 0; i < n; i++) {
		if (dp[i] <= dp[i + 1]) {
			bigger[i + 1] = bigger[i] + 1;
		}
		else {
			bigger[i + 1] = 1;
		}

		if (dp[i] >= dp[i + 1]) {
			smaller[i + 1] = smaller[i] + 1;
		}
		else {
			smaller[i + 1] = 1;
		}
		
	}

	for (int i = 0; i < n; i++) {
		big = max(big, bigger[i]);
		small = max(small, smaller[i]);
	}
	cout << max(big, small) << endl;
}