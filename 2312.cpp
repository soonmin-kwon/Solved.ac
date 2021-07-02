#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;	

	for (int i = 0; i < t; i++) {
		cin >> n;
		int m = n;
		for (int j = 2; j <= m; j++) {
			if (n == 1) {
				break;
			}
			int k =0;
			while (n % j == 0) {
				n = n / j;
				k++;
			}
			if (k != 0) {
				cout << j << " " << k << "\n";
			}			
		}
	}
}