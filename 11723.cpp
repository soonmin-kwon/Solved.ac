#include<iostream>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int m,p, bit = 0;

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (s == "check") {
			cin >> p;
			if (bit & 1 << p) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
				continue;
			}
		}
		if (s == "add") {
			cin >> p;
			bit |= 1 << p;
		}
		if (s == "remove") {
			cin >> p;
			bit &= ~(1 << p);
		}
		
		if (s == "toggle") {
			cin >> p;
			bit ^= 1 << p;
		}
		if (s == "all") {
			bit = (1 << 21) - 1;
		}
		if (s == "empty") {
			bit = 0;
		}
	}
}