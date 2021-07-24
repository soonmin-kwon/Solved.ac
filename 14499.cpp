#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

queue<int> command;
int map[21][21];
int dice[6];
int diceCopy[6];
int x, y, n, m;
int mX[4] = { 0, 0,  -1, 1 };
int mY[4] = { 1, -1, 0, 0 };

void RollEast() {
	dice[0] = diceCopy[2];
	dice[1] = diceCopy[0];
	dice[2] = diceCopy[5];
	dice[5] = diceCopy[1];

	cout << dice[0] << "\n";
}

void RollWest() {
	dice[0] = diceCopy[1];
	dice[1] = diceCopy[5];
	dice[2] = diceCopy[0];
	dice[5] = diceCopy[2];

	cout << dice[0] << "\n";
}

void RollSouth() {
	dice[0] = diceCopy[4];
	dice[3] = diceCopy[0];
	dice[4] = diceCopy[5];
	dice[5] = diceCopy[3];

	cout << dice[0] << "\n";
}

void RollNorth() {
	dice[0] = diceCopy[3];
	dice[3] = diceCopy[5];
	dice[4] = diceCopy[0];
	dice[5] = diceCopy[4];

	cout << dice[0] << "\n";
}

void RollDice() {
	while (!command.empty()) {
		int com = command.front() - 1;
		command.pop();
		
		int nX = x + mX[com];
		int nY = y + mY[com];

		if (nX < 0 || nX >= n || nY < 0 || nY >= m) {
			continue;
		}

		copy(dice, dice + 6, diceCopy);

		if (com == 0) {
			RollEast();		
		}
		else if (com == 1) {
			RollWest();
		}
		else if (com == 2) {
			RollNorth();
		}
		else if (com == 3){
			RollSouth();
		}

		if (map[nX][nY] == 0) {
			map[nX][nY] = dice[5];
		}
		else {
			dice[5] = map[nX][nY];
			map[nX][nY] = 0;
		}

		x = nX;
		y = nY;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, c;
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> c;
		command.push(c);
	}
	
	RollDice();
}