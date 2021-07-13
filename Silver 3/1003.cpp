#include<iostream>
using namespace std;

int sol[41][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, p;
	cin >> n;

	sol[0][0] = 1;
	sol[1][1] = 1;	

	for (int i = 2; i <= 40; i++) {
		sol[i][0] = sol[i - 2][0] + sol[i - 1][0];
		sol[i][1] = sol[i - 2][1] + sol[i - 1][1];		
	}

	for (int i = 0; i < n; i++) {
		cin >> p;
		cout << sol[p][0] << " " << sol[p][1] << "\n";
	}
}
