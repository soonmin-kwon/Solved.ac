#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m, ans = 0;

int mX[4] = { 1, 0, -1, 0 };
int mY[4] = { 0, 1, 0, -1 };

int map[8][8];
int mapCopy[8][8];
int mapAfter[8][8];

void BFS() {
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mapAfter[i][j] = mapCopy[i][j];
			if (mapAfter[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nX = x + mX[i];
			int nY = y + mY[i];

			if (nX >= 0 && nX < m && nY >= 0 && nY < n) {
				if (mapAfter[nY][nX] == 0) {
					mapAfter[nY][nX] = 2;
					q.push(make_pair(nY, nX));
				}
			}
		}
	}

	int ansTemp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mapAfter[i][j] == 0) {
				ansTemp++;
			}
		}
	}

	ans = max(ans, ansTemp);
}

void Wall(int count) {
	if (count == 3) {
		BFS();
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mapCopy[i][j] == 0) {
				mapCopy[i][j] = 1;
				Wall(count + 1);
				mapCopy[i][j] = 0;
			}
		}
	}
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
			if (map[i][j] == 0) {
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < m; l++) {
						mapCopy[k][l] = map[k][l];
					}
				}
				mapCopy[i][j] = 1;
				Wall(1);
				mapCopy[i][j] = 0;
			}
		}
	}

	cout << ans;
}