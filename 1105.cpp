#include<iostream>
#include<string>
using namespace std;

int main() {
	
	string l, r;
	cin >> l >> r;

	int ans = 0;
	if (l.length() == r.length()) {	
		for (int i = 0; i < l.length(); i++) {
			if (l[i] != r[i]) {
				break;
			}
			else {
				if (l[i] == '8') {
					ans++;
				}
			}
		}
	}

	cout << ans << endl;

}