#include<iostream>
#include<cstring>
using namespace std;

bool visitied[1001];
bool map[1001][100];
int n;

void dfs(int start) {
	if (visitied[start]) {		
		return;
	}
	visitied[start] = true;
	for (int i = 1; i <= n; i++) {
		if (map[start][i] == true && !visitied[i]) {			
			dfs(i);
			break;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;	
	int p;
	int answer = 0;
	for (int j = 0; j < t; j++) {
		cin >> n;
		
		answer = 0;
		for (int i = 1; i <= n; i++) {
			cin >> p;
			map[i][p] = true;
		}

		for (int i = 1; i <= n; i++) {
			if (!visitied[i]) {
				dfs(i);
				answer++;
			}
		}
		cout << answer << "\n";		
		for (int i = 0; i <= n; i++) {
			memset(map[i], false, sizeof(map[i]));
		}
		memset(visitied, false, sizeof(visitied));
	}
	
}