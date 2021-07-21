#include<iostream>
using namespace std;

int map[51][51];
int ans = 0;
int mY[4] = { -1, 0, 1, 0 };
int mX[4] = { 0, 1, 0, -1 };

void RobotCleaner(int r, int c, int state) {
	int check = 0;

	if (map[r][c] == 0) {
		map[r][c] = 2;
		ans++;
	}

	for (int i = 0; i < 4; i++) {
		// 3 -> 2 -> 1 -> 0
		int nS = (state + 3 - i) % 4;
		int nX = c + mX[nS];
		int nY = r + mY[nS];
		
		if (map[nY][nX] == 0) {
			RobotCleaner(nY, nX, nS);
		}
		else {
			check++;
		}
	}

	if (check == 4) {
		int nS = (state + 2) % 4;
		int nX = c + mX[nS];
		int nY = r + mY[nS];

		if (map[nY][nX] == 2) {
			RobotCleaner(nY, nX, state);
		}
		else {
			cout << ans;
			exit(0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int r, c, state;
	
	cin >> n >> m;
	cin >> r >> c >> state;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	RobotCleaner(r, c, state);		
}
