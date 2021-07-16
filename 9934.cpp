#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int building[1024];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, index = 1;
	int len;
	cin >> k;
	len = (int)(pow(2, k)) - 1;

	int root = len / 2 + 1;

	for (int i = 1; i <= len; i++) {
		cin >> building[i];
	}

	cout << building[root] << "\n";

	for (int i = 1; i < k; i++) {
		root = root / 2;

		for (int j = root; j <= len; j += 2 * root) {
			cout << building[j] << " ";
		}
		cout << "\n";
	}
}