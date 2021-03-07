#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int n,k;
	int sum = 0;
	int sol = -10001;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k;
		sum += k;
		sol = max(sol, sum);
		sum = max(sum, 0);

	}
	cout << sol << endl;
}