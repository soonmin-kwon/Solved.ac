#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int s, e;
	cin >> s >> e;
	int ans = 0;
	bool* sol = new bool[e+1];
	if (e == 1) {
		cout << ans << endl;
		return 0;
	}

	for (int i = 2; i <= e; i++) {
		sol[i] = true;
	}

	for (int i = 2; i * i <= e; i++) {
		if (sol[i]) {
			for (int j = i * i; j <= e; j += i) {
				sol[j] = false;
			}
		}
	}
	for (int i = s; i <= e; i++) {
		if (sol[i]) {
			cout << i << '\n';
		}
	}	

}