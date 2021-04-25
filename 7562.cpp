#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

bool map[301][301];
int sol[301][301];
int moveX[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int moveY[] = { 2, 1, -1, -2, 2, 1, -1, -2 };

queue<pair<int, int>> q;
int n, l, sx, sy, fx, fy;

void bfs(int ix, int iy) {
	q.push(make_pair(ix, iy));
	map[ix][iy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == fx && y == fy) {			
			cout << sol[x][y] << endl;

			while (!q.empty()) {
				q.pop();
			}
			break;
		}
		
		for (int i = 0; i < 8; i++) {
			int nx = x + moveX[i];
			int ny = y + moveY[i];

			if (nx >= 0 && nx < l && ny >= 0 && ny < l) {
				if (!map[nx][ny]) {
					map[nx][ny] = true;
					q.push(make_pair(nx, ny));
					sol[nx][ny] = sol[x][y] +1;
				}
			}			
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> l >> sx >> sy >> fx >> fy;
		bfs(sx, sy);
		memset(sol, 0, sizeof(sol));
		memset(map, false, sizeof(map));
	}
}