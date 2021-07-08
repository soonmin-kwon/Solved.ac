#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	bool prime[10002];
	int n, t;

	for (int i = 2; i <= 10001; i++) {
		prime[i] = true;
	}

	for (int i = 2; i * i <= 10001; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= 10001; j += i) {
				prime[j] = false;
			}
		}
	}
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t;
		for (int j = 0; j <= t / 2; j++) {
			if (prime[t / 2 - j] && prime[t / 2 + j]) {
				cout << t / 2 - j << " " << t / 2 + j << "\n";
				break;
			}
		}
	}
}