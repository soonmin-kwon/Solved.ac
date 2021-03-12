#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int n, c, k;
	cin >> n >> c;
	int t = 0;
	int ind = 1;
	int sol[10] = { 0 ,};
	for (int i = 0; i < n; i++) {
		cin >> k;
		sol[i] = k;
		if (c >= sol[i]) {
			t = max(t, sol[i]);
			ind = i;
		}		

	}
	int check = 0;
	while (c != 0) {		
		if (c >= t) {
			c -= t;
			check++;

		}
		else {
			t = sol[ind--];
					
		}
	}
	cout << check << endl;
}