#include<iostream>
using namespace std;

int sol[246913];

int main() {
	ios::sync_with_stdio(false);

	int n;
	
	int ans = 0;
	
	sol[1] = 1;
	
	for (int i = 2; i * i <= 246912; i++) {
		if (sol[i] == 0) {
			for (int j = i * i; j <= 246912; j += i) {
				sol[j] = 1;
			}
		}
	}	
	while (true) {
		int ans = 0;
		cin >> n;
		if (n == 0) {
			break;
		}

		for (int i = n+1; i <= 2 * n; i++) {

			if (sol[i] == 0) {
				ans++;
		
			}
		}
		cout << ans << endl;
		
	}

}