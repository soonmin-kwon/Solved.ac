#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string pas[101][101];

string add(string a, string b) {	
	string output="";
	int sum = 0;
	int aS = a.size();
	int bS = b.size();		
	int temp = aS;
	if (aS > bS) {
		temp = aS;
		for (int i = 0; i < aS - bS; i++) {
			b = "0" + b;
		}		
	}
	if (bS > aS) {
		temp = bS;
		for (int i = 0; i < bS - aS; i++) {
			a = "0" + a;
		}		
	}
	for (int i = temp-1; i >=0; i--) {
		sum += (a[i] - '0') + (b[i] - '0');
		output = to_string(sum%10) + output;
		sum = sum / 10;
	}
	if (sum != 0) {
		output = to_string(sum) + output;
	}		
	return output;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;

	cin >> n >> m;	
	pas[1][0] = "1";
	pas[1][1] = "1";
	for (int i = 2; i < 101; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				pas[i][j] = "1";
			}
			else {
				pas[i][j] = add(pas[i - 1][j - 1] , pas[i - 1][j]);
			}
			if (i == n && j == m) {
				cout << pas[n][m] << "\n";
				return 0;
			}
		}
	}	
}