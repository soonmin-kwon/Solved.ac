#include<iostream>
#include<vector>
using namespace std;

int depth[50001];
int ancestor[50001][16];
vector<int> tree[50001];

void MakeAncestor(int cur, int parent) {
	depth[cur] = depth[parent] + 1;

	ancestor[cur][0] = parent;

	for (int i = 1; i <= 15; i++) {
		ancestor[cur][i] = ancestor[ancestor[cur][i - 1]][i - 1];
	}

	int len = tree[cur].size();
	for (int i = 0; i < len; i++) {
		int child = tree[cur][i];
		if (child != parent) {
			MakeAncestor(child, cur);
		}
	}
}

void FindLCA(int node1, int node2) {
	if (depth[node1] != depth[node2]) {
		if (depth[node1] > depth[node2]) {
			int temp = node2;
			node2 = node1;
			node1 = temp;
		}

		for (int i = 15; i >= 0; i--) {
			if (depth[node1] <= depth[ancestor[node2][i]]) {
				node2 = ancestor[node2][i];
			}
		}
	}

	if (node1 == node2) {
		cout << node1 << "\n";
		return;
	}

	int lca = node1;

	for (int i = 15; i >= 0; i--) {
		if (ancestor[node1][i] != ancestor[node2][i]) {
			node1 = ancestor[node1][i];
			node2 = ancestor[node2][i];
		}
		else {
			lca = ancestor[node1][i];
		}
	}
	cout << lca << "\n";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int node1, node2;

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> node1 >> node2;
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	depth[0] = -1;
	MakeAncestor(1, 0);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2;
		FindLCA(node1, node2);
	}
}