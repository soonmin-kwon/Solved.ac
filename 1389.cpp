#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int kevin[101][101]{};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, f1, f2, temp, ans, bacon = 987654321;
	
	cin >> n >> m;	
	for (int i = 0; i < m; i++) {
		cin >> f1 >> f2;
		kevin[f1][f2] = 1;
		kevin[f2][f1] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j == k) {
					continue;
				}
				if (kevin[j][i] != 0 && kevin[i][k] != 0) {
					if (kevin[j][k] == 0) {
						kevin[j][k] = kevin[i][k] + kevin[j][i];
					}
					else {
						kevin[j][k] = min(kevin[j][i] + kevin[i][k], kevin[j][k]);
					}					
				}				
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		temp = 0;
		for (int j = 1; j <= m; j++) {
			temp += kevin[i][j];
		}
		if (bacon > temp) {
			bacon = temp;
			ans = i;
		}
	}
	cout << ans << "\n";
}