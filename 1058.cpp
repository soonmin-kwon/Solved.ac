#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int friends[51][51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, temp, ans = 0;
	string input;
	cin >> n;
	for (int i = 1; i <= n; i++) {		
		cin >> input;
		for (int j = 1; j <= input.size(); j++) {
			if (input[j - 1] == 'Y') {
				friends[i][j] = 1;
			}
			else {
				friends[i][j] = 987654321;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {				
				friends[j][k] = min(friends[j][i] + friends[i][k],friends[j][k]);				
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		temp = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			if (friends[i][j] == 1 || friends[i][j] == 2) {
				temp++;
			}			
		}
		ans = max(ans, temp);
	}
	cout << ans << "\n";
}