#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	
	int n, s;
	while (true) {
		cin >> n;
		if (n == 0) {
			return 0;
		}

		vector<int> v;
		vector<bool>check(n, false);

		for (int i = 0; i < 6; i++) {
			check[i] = true;
		}

		for (int i = 0; i < n; i++) {
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		do {
			for (int i = 0; i < n; i++) {
				if (check[i]) {
					cout << v[i] << " ";
				}
			}
			cout << "\n";
		} while (prev_permutation(check.begin(), check.end()));
		cout << "\n";
	}
}