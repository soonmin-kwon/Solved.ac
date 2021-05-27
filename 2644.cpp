#include<iostream>
using namespace std;

bool fam[101][101];
bool visited[101] = { false, };
int n, x, y,m;
int answer2 = -1;

void dfs(int start, int end,int before, int answer) {		
	if (start == end) {
		answer2 = answer;
		return;
	}
	for (int i = 1; i <= m; i++) {
		if (fam[start][i] && i!= before) {
			dfs(i, end, start, answer+1);			
		}
	}
	return;
}

int main() {
	
	cin >> m;
	cin >> x >> y;
	cin >> n;
	int inpx,inpy;
	
	for (int i = 0; i < n; i++) {
		cin >> inpx >> inpy;
		fam[inpx][inpy] = true;
		fam[inpy][inpx] = true;
	}	
	dfs(x, y,0,0);
	cout << answer2 << "\n";
}