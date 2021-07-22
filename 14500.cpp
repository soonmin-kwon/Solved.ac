#include<iostream>
#include<algorithm>
using namespace std;

int map[501][501];
int mX[4] = { 1, 0, -1, 0 };
int mY[4] = { 0, 1, 0, -1 };

int n, m;
int ans = 0;

void Tetromino(int y, int x, int cnt, int maximum, int pY, int pX) {
	maximum += map[y][x];

	if (cnt == 3) {
		ans = max(maximum, ans);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nX = x + mX[i];
		int nY = y + mY[i];

		if (nX >= 0 && nX <= m && nY >= 0 && nY <= n) {
			if (!(nX == pX && nY == pY)) {
				Tetromino(nY, nX, cnt + 1, maximum, y, x);
			}			
		}
	}
}

void Tetromino2(int y, int x) {
	int temp = 0;
	if (y + 2 <= n && x + 1 <= m) {
		temp = max(temp, map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x + 1]);
	}

	if (y + 2 <= n && x - 1 >= 0 ) {
		temp = max(temp, map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x - 1]);
	}

	if (y -1 >= 0 && x + 2 <= m) {
		temp = max(temp, map[y][x] + map[y - 1][x + 1] + map[y][x + 1] + map[y][x + 2]);
	}

	if (y + 1 <= n && x + 2 <= m) {
		temp = max(temp, map[y][x] + map[y + 1][x + 1] + map[y][x + 1] + map[y][x + 2]);
	}

	ans = max(ans, temp);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Tetromino(i, j, 0, 0, -1, -1);
			Tetromino2(i, j);
		}
	}

	cout << ans;
}
