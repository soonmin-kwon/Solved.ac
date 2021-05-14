#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, k;
queue <pair<int,int>> q;
bool visitied[100001];

void bfs(int nx) {
	
	while (!q.empty()) {
		int x = q.front().first;
		int sol = q.front().second;
		q.pop();
		if (x == k) {
			cout << sol << endl;
			return;
		}

		if (x + 1 < 100001 && !visitied[x + 1]) {
			q.push(make_pair(x + 1, sol + 1));
			visitied[x + 1] = true;
		}
		if (x - 1 >= 0 && !visitied[x - 1]) {
			q.push(make_pair(x - 1, sol + 1));
			visitied[x - 1] = true;
		}

		if (x * 2 < 100001 && !visitied[2 * x]) {
			q.push(make_pair(2 * x, sol + 1));
			visitied[2 * x] = true;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	q.push(make_pair(n, 0));
	visitied[n] = true;	
	bfs(n);
}