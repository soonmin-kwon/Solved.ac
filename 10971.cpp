#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int map[11][11];
bool visitied[11];
int n;
int ans = INT_MAX;
void dfs(int start, int cur, int sum,int cnt) {
	if (cur == start && cnt == n) {
		ans = min(ans, sum);
		return;
	}

	for (int i = 1; i <= n; i++) {				
		if (!visitied[cur] && map[cur][i] != 0) {
			visitied[cur] = true;
			sum += map[cur][i];
			if (sum <= ans) {
				dfs(start, i, sum, cnt + 1);
			}			
			visitied[cur] = false;
			sum -= map[cur][i];
		}		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		dfs(i, i, 0,0);
	}
	cout << ans << "\n";
}