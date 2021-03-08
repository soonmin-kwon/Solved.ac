#include<iostream>
using namespace std;

int fib[1000001];

int main() {

	int n,pm = 1;
	cin >> n;
	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 1;
	if (n < 0) {
		n = -n;
		if (n % 2 == 0) {
			pm = -1;
		}
	}	
	for (int i = 3; i <= n; i++) {
		fib[i] = (fib[i - 1] + fib[i - 2]) % 1000000000;
	}

	if (fib[n] == 0) {
		pm = 0;
	}
	cout << pm << endl;
	cout << fib[n] % 1000000000 << endl;
}