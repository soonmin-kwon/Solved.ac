#include<iostream>
using namespace std;

char map[251][251];
bool visitied[251][251];
int mX[4] = { 1,0,-1,0 };
int mY[4] = { 0,1,0,-1 };
int r, c;
int sheep, wolf;
void DFS(int x, int y) {
	visitied[x][y] = true;
	if (map[x][y] == '#') {
		return;
	}
	if (map[x][y] == 'o') {
		sheep++;		
	}
	if (map[x][y] == 'v') {
		wolf++;		
	}
	
	for (int i = 0; i < 4; i++) {
		int nX = x + mX[i];
		int nY = y + mY[i];

		if (nX >=0 && nX < r && nY >=0 && nY < c && !visitied[nX][nY]) {
			DFS(nX, nY);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ansS = 0 , ansW = 0;
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!visitied[i][j] && map[i][j] != '#') {
				DFS(i, j);
				if (sheep > wolf) {
					ansS += sheep;
				}
				else {
					ansW += wolf;
				}
				sheep = wolf = 0;
			}
		}
	}
	cout << ansS << " " << ansW << "\n";
}