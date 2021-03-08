#include<iostream>
using namespace std;

int main() {
	long long int fib[117];

	int n;
	cin >> n;
	fib[0] = 1;
	fib[1] = 1;
	fib[2] = 1;

	for (int i = 3; i < n; i++) {
		fib[i] = fib[i - 1] + fib[i - 3];
	}
	cout << fib[n - 1] << endl;
}