#include<iostream>
using namespace std;

void dfs(int start);
bool graph[1001][1001];
bool visited[1001];
int n, m;
int cnt = 0;

int main() {	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int comp1, comp2;
	for (int i = 0; i < m; i++) {
		cin >> comp1 >> comp2;
		graph[comp1][comp2] = true;
		graph[comp2][comp1] = true;
	}
		
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt++;
			dfs(i);
		}			
	}
	cout << cnt << endl;

}

void dfs(int start) {
	visited[start] = true;
	for (int i = 1; i <= n; i++) {
		if (graph[start][i] && !visited[i]) {
			dfs(i);
		}
	}	
}