#include<iostream>
#include<cstring>
using namespace std;

char nonColorBlind[101][101];
char ColorBlind[101][101];
int mX[4] = { 1,0,-1,0 };
int mY[4] = { 0,1,0,-1 };
bool visitied[101][101];
int n;

void RegionNone(int x, int y, char color) {
	visitied[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nX = x + mX[i];
		int nY = y + mY[i];

		if (nX >= 0 && nX < n && nY >= 0 && nY < n) {
			if (!visitied[nX][nY] && nonColorBlind[nX][nY] == color) {
				RegionNone(nX, nY, color);
			}			
		}
	}
}

void Region(int x, int y, char color) {
	visitied[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nX = x + mX[i];
		int nY = y + mY[i];

		if (nX >= 0 && nX < n && nY >= 0 && nY < n) {
			if (!visitied[nX][nY] && ColorBlind[nX][nY] == color) {
				Region(nX, nY, color);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string p;
	int ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p;
		for (int j = 0; j < n; j++) {
			nonColorBlind[i][j] = p[j];
			if (p[j] == 'G') {
				ColorBlind[i][j] = 'R';
			}
			else {
				ColorBlind[i][j] = p[j];
			}			
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visitied[i][j]) {
				RegionNone(i, j, nonColorBlind[i][j]);
				ans++;
			}
		}
	}

	cout << ans << " ";
	memset(visitied, false, sizeof(visitied[0][0]) * 101 * 101);
	ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visitied[i][j]) {
				Region(i, j, ColorBlind[i][j]);
				ans++;
			}
		}
	}

	cout << ans;
}