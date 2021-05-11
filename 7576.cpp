#include<iostream>
#include<queue>
using namespace std;

int map[1001][1001];
int sol[1001][1001];
int mx[] = { 0,1,0,-1 };
int my[] = { -1,0,1,0 };
int m, n;
int temp = 0;
queue<pair<int, int>> q;

void bfs() {		
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (map[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					map[nx][ny] = 1;
					sol[nx][ny] = sol[x][y] + 1;

					if (temp <= sol[nx][ny]) {
						temp = sol[nx][ny];
					}
				}								
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n;	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			sol[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));				
			}
		}
	}	
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << temp << endl;
}