#include<iostream>
using namespace std;

int map[101][101];
long long answer[101][101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			answer[i][j] = 0;
		}
	}
	answer[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == n && j == n) {
				cout << answer[i][j] << endl;
				return 0 ;
			}
			if (answer[i][j] == 0) {
				continue;
			}
			if (i + map[i][j] <= n) {
				answer[i + map[i][j]][j] = answer[i][j] + answer[i+map[i][j]][j];
			}
			if (j + map[i][j] <= n) {
				answer[i][j + map[i][j]] = answer[i][j] + answer[i][j + map[i][j]];
			}
		}
	}	
}