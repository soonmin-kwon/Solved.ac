#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> tree[40001];
int ancestor[40001][16];
int dist[40001];
int depth[40001];

void MakeArrays(int cur, int parent, int distance) {
	depth[cur] = depth[parent] + 1;

	if (cur != 1) {
		dist[cur] = dist[parent] + distance;
	}

	ancestor[cur][0] = parent;	

	for (int i = 1; i <= 15; i++) {
		ancestor[cur][i] = ancestor[ancestor[cur][i - 1]][i - 1];
	}

	int len = tree[cur].size();	

	for (int i = 0; i < len; i++) {
		int child = tree[cur][i].first;
		if (child != parent) {
			MakeArrays(child, cur, tree[cur][i].second);
		}
	}
}

int FindDistance(int node1, int node2) {
	int distance = dist[node1] + dist[node2];

	if (depth[node1] != depth[node2]) {
		if (depth[node1] > depth[node2]) {
			int temp = node1;
			node1 = node2;
			node2 = temp;
		}

		for (int i = 15; i >= 0; i--) {
			if (depth[node1] <= depth[ancestor[node2][i]]) {
				node2 = ancestor[node2][i];
			}
		}
	}

	if (node1 == node2) {
		return distance - 2 * dist[node1];
	}

	int lca = node1;

	for (int i = 15; i >= 0; i--) {
		if (ancestor[node1][i] != ancestor[node2][i]) {
			node1 = ancestor[node1][i];
			node2 = ancestor[node2][i];
		}
		else if (ancestor[node1][i] != 0) {
			lca = ancestor[node1][i];
		}
	}

	return distance - 2 * dist[lca];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int node1, node2, distance;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> node1 >> node2 >> distance;
		tree[node1].push_back(make_pair(node2, distance));
		tree[node2].push_back(make_pair(node1, distance));
	}
	depth[0] = -1;
	MakeArrays(1, 0, 0);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2;
		cout << (FindDistance(node1, node2)) << "\n";
	}
}