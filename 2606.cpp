#include<iostream>
#include<algorithm>
using namespace std;

bool computer[101][101];
bool visitied[101];
int n, m, cnt;

void DFS(int x) {
	cnt += 1;
	visitied[x] = true;
	for (int i = 1; i <= n; i++) {
		if (computer[x][i] && !visitied[i]) {
			DFS(i);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	int c1, c2;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> c1 >> c2;
		computer[c1][c2] = true;
		computer[c2][c1] = true;
	}
	DFS(1);
	cout << cnt-1 << "\n";
}