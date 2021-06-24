#include<iostream>
using namespace std;

int sol[12];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;
	cin >> t; 
	sol[1] = 1;
	sol[2] = 2;
	sol[3] = 4;

	for (int i = 0; i < t; i++) {
		cin >> n;
		if (sol[n] == 0) {
			for (int j = 4; j <= n; j++) {
				sol[j] = sol[j - 1] + sol[j - 2] + sol[j - 3];
			}
		}		
		cout << sol[n] << "\n";
	}	
}