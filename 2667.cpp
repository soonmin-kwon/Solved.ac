#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int map[27][27]{};
bool visited[27][27];
int mx[] = {1, 0, -1, 0};
int my[] = {0, -1, 0, 1};
int sol = 0;
int temp=1;

void dfs(int x, int y) {	
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + mx[i];
		int ny = y + my[i];

		if (map[nx][ny] == 1 && !visited[nx][ny]) {
			dfs(nx, ny);
			temp++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	int n;
	cin >> n;
	vector<int> count;

	for (int i = 1; i <= n; i++) {	
		cin >> input;
		for (unsigned int j = 1; j <= input.length(); j++) {
			map[i][j] = input[j-1] - '0';
		}				
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				sol++;
				dfs(i, j);
				count.push_back(temp);
				temp = 1;
			}
		}
	}
	cout << sol << endl;
	sort(count.begin(), count.end());
	for (unsigned int i = 0; i < count.size(); i++) {
		cout << count[i] << endl;
	}
}
