#include <iostream>
#include <cmath>
using namespace std;
long long int sol[1001][5];

long long int T(int n, int r) {
	if(n == 1){			
		return 1;
	}
	if (r == 3) {		
		return (long long int)(pow(2, n) - 1);
	}	
	long long k = n - round(sqrt(2 * n + 1)) + 1;
	sol[n][r] = 2 * T(k, r) + T(n - k, r - 1);	
	return sol[n][r];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;	
	int index = 1;

	while(cin >> n) {		
		cout << "Case " << index << ": " << T(n, 4)<<"\n";		
		index++;
	}
}