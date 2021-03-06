#include<iostream>
#include<algorithm>
using namespace std;

int map[1000];
int sol[1000] = {0, };

int main() {
	int n,a;
	int solv = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a;
		map[i] = a;
	}

	if (n == 1) {
		solv = 0;
		cout << solv << endl;
		return 0;
	}
	if (map[0] == 0) { 
		solv = -1; 
		cout << solv << endl;
		return 0;
	}
	
	sol[0] = 1;
	for (int i = 0; i < n; i++) {
		
		if (map[i] == 0) {
			continue;
		}

		for (int j = 1; j <= map[i]; j++) {
			if (sol[i + j] == 0) {
				if(sol[i] != 0)
					sol[i + j] = sol[i] + 1;				
			}
			else {
				sol[i + j] = min(sol[i] + 1, sol[i + j]);
			}							
			if (i + j >= n-1) {
				cout << sol[i + j] -1 << endl;
				return 0 ;
			}
			
		}
	}
	cout << -1 << endl;
}