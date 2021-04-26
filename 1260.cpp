#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

bool map[1001][1001];
bool visited[1001];
queue<int> q;
int n, m, v;
void dfs(int v) {
	cout << v ;
	visited[v] = true;
	for (int i = 1; i <=n; i++) {
		if (map[v][i] && !visited[i]) {
			cout << " ";
			dfs(i);
		}
	}	
}
void bfs(int v) {
	visited[v] = true;
	q.push(v);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v << " ";
		for (int i = 1; i <= n; i++) {
			if (map[v][i] && !visited[i]) {
				visited[i] = true;
				q.push(i);

			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int sv, dv;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> sv >> dv;
		map[sv][dv] = true;
		map[dv][sv] = true;
	}

	dfs(v);
	cout << endl;
	memset(visited, false, sizeof(visited));
	bfs(v);
	cout << endl;
}	