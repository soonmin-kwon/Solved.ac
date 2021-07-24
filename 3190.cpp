#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<pair<int, char>> command;

int map[101][101];
int mX[4] = { 0, 1, 0, -1 };
int mY[4] = { 1, 0, -1, 0 };
int n;

void MoveSnake() {
	deque<pair<int, int>> dq;

	int x = 0, y = 0, dir = 0, time = 0, idx =0;
	int len = command.size();
	dq.push_back(make_pair(x, y));

	map[x][y] = 1;

	while (true) {
		time++;

		int nX = x + mX[dir];
		int nY = y + mY[dir];

		if (nX < 0 || nX >= n || nY < 0 || nY >= n || map[nX][nY] == 1) {
			break;
		}

		if (map[nX][nY] == 0) {
			map[nX][nY] = 1;
			map[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
			dq.push_front(make_pair(nX, nY));
		}
		else if (map[nX][nY] == 2) {
			map[nX][nY] = 1;
			dq.push_front(make_pair(nX, nY));
		}

		if (idx < len) {
			if (time == command[idx].first) {
				if (command[idx].second == 'L') {
					dir = (dir + 3) % 4;
				}
				else if (command[idx].second == 'D') {
					dir = (dir + 1) % 4;
				}
				idx++;
			}
		}
		x = nX;
		y = nY;
	}

	cout << time;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, l, apple1, apple2;
	int time;
	char c;


	cin >> n >> k;	
	
	for (int i = 0; i < k; i++) {
		cin >> apple1 >> apple2;

		map[apple1 - 1][apple2 - 1] = 2;
	}

	cin >> l;

	for (int i = 0; i < l; i++) {
		cin >> time >> c;
		command.push_back(make_pair(time, c));
	}

	MoveSnake();
}