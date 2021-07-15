#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> tree[1000001];
int countAdaptor[1000001][2];

void CountEarlyAdpator(int prev, int cur) {	
	countAdaptor[cur][0] = 0;
	countAdaptor[cur][1] = 1;

	int len = tree[cur].size();

	for (int i = 0; i < len; i++) {
		int next = tree[cur][i];

		if (next == prev) {
			continue;
		}

		CountEarlyAdpator(cur, next);

		countAdaptor[cur][1] += min(countAdaptor[next][0], countAdaptor[next][1]);
		countAdaptor[cur][0] += countAdaptor[next][1];
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, u, v;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	CountEarlyAdpator(0, 1);

	cout << min(countAdaptor[1][0], countAdaptor[1][1]);
}