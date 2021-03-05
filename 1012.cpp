#include<iostream>
#include<vector>
using namespace std;

int map[51][51];
int mx[4] = { -1,0,1,0 };
int my[4] = { 0,-1,0,1 };
bool visited[51][51];
int t, m, n, k;

void fill(int x, int y) {
	visited[x][y] = true;	
	for (int a = 0; a < 4; a++) {
		int nx = x + mx[a];
		int ny = y + my[a];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue;
		}

		if (map[nx][ny] == 0 || visited[nx][ny]) {
			continue;
		}
		else {
			fill(nx, ny);
		}		
	}
	
}

int main() {
	int solve = 0;

	int x, y;
	cin >> t;
	for (int c = 0; c < t; c++) {
		int solve = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = 0;
				visited[i][j] = false;
			}
		}

		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[y][x] = 1;
		}		

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					fill(i, j);
					solve++;
				}
			}
		}
		cout << solve << endl;
	}
}