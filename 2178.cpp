#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int map[101][101];
bool visited[101][101];
int sol[101][101];
int mx[] = { 0, -1, 0, 1 };
int my[] = { 1, 0, -1, 0 };
queue<pair<int, int>> q;
int n, m;

void bfs(int nx, int ny) {	
	q.push(make_pair(nx, ny));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == n-1 && y == m-1) {
			cout << sol[x][y] << endl;
			while (!q.empty()) {
				q.pop();
			}
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (map[nx][ny] == 1 && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
					sol[nx][ny] = sol[x][y] + 1;
				}
			}			
		}		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;	
	cin >> n >> m;
	vector<int> count;
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < m; j++) {			
			map[i][j] = input[j] - '0';
		}
	}

	sol[0][0] = 1;
	visited[0][0] = true;
	bfs(0, 0);
}