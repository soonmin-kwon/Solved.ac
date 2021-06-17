#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, l, len, x =-1;
	cin >> n >> l;
	if (l > 100) {
		cout << -1 << "\n";
		return 0;
	}	
	for (int i = l; i <= 100; i++) {
		if ((n - (i * (i - 1)) / 2) % i == 0 && (n - (i * (i - 1)) / 2) / i >=0) {
			x = (n - (i * (i - 1)) / 2) / i;
			len = i;
			break;
		}
	}
	if (x == -1) {
		cout << x << "\n";
		return 0;
	}
	for (int i = 0; i < len; i++) {
		cout << x + i << " ";
	}
}