#include <iostream>
using namespace std;

long long d[1000001];

int main() {	
	
	int t,n;
	cin >> t;
	
	d[0] = 0;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;	
	
	for (int j = 0; j < t; j++) {
		cin >> n;
		for (int i = 4; i <=n; i++) {
			d[i] = (d[i - 3] + d[i - 2] + d[i - 1]) % 1000000009;
			
		}
		cout << d[n]<< endl;
	}
	
	return 0;
}