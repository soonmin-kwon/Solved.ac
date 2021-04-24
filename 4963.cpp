#include<iostream>
using namespace std;

int map[52][52]{};
bool visited[52][52];
int moveY[] = { 0,1,0,-1, 1,1,-1,-1 };
int moveX[] = { 1,0,-1,0, 1,-1,1,-1 };
int sol = 0;

void dfs(int y, int x) {

	visited[y][x] = true;

	for (int i = 0; i < 8; i++) {

		int nextY = y + moveY[i];
		int nextX = x + moveX[i];		

		if (map[nextY][nextX] && !visited[nextY][nextX]) {
			dfs(nextY, nextX);
		}						
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int w = 1, h = 1;
	while (w !=0 || h!=0) {
		int land;
		cin >> w >> h;
		
		if (w == 0 && h == 0) {
			break;
		}
		
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> land;
				map[i][j] = land;
			}
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					dfs(i, j);
					sol++;
				}
			}
		}
		cout << sol << endl;

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {				
				map[i][j] = 0;
				visited[i][j] = false;
			}
		}
		sol = 0;
	}
	
}