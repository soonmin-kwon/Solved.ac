#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;
	unsigned long long int sol = 1;
	//cout << n % 100000 << endl;
	for (int i = n; i >= 1; i--) {
		sol *= i;
		if (sol % 10 == 0) {
			sol /= 10;
		}					
		sol %= 1000000000000;
	}
	sol %= 100000;
	if (sol < 10000) {
		cout << 0 << sol << endl;
	}
	else {
		cout << sol << endl;
	}
}