#include<iostream>
using namespace std;

int sol[51]{};

int main() {
	int n;
	cin >> n;
	sol[0] = 1;
	sol[1] = 1;
	sol[2] = 3;
	for (int i = 3; i <= n; i++) {
		sol[i] = (sol[i - 1] + sol[i - 2] + 1) % 1000000007;
	}	
	
	cout << sol[n] << endl;
}

