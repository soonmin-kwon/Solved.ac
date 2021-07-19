#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int ancestor[10001][15];
int depth[10001];
bool checkRoot[10001];
vector<int> tree[10001];

void MakeArrays(int cur, int parent) {
	depth[cur] = depth[parent] + 1;

	ancestor[cur][0] = parent;

	for (int i = 1; i <= 14; i++) {
		ancestor[cur][i] = ancestor[ancestor[cur][i - 1]][i - 1];
	}

	int len = tree[cur].size();

	for (int i = 0; i < len; i++) {
		int child = tree[cur][i];

		if (child != parent) {
			MakeArrays(child, cur);
		}
	}
}

int FindLCA(int node1, int node2) {
	if (depth[node1] != depth[node2]) {
		if (depth[node1] > depth[node2]) {
			int temp = node1;
			node1 = node2;
			node2 = temp;
		}

		for (int i = 14; i >= 0; i--) {
			if (depth[node1] <= depth[ancestor[node2][i]]) {
				node2 = ancestor[node2][i];
			}
		}
	}

	if (node1 == node2) {
		return node1;
	}

	int lca = node1;

	for (int i = 14; i >= 0; i--) {
		if (ancestor[node1][i] != ancestor[node2][i]) {
			node1 = ancestor[node1][i];
			node2 = ancestor[node2][i];
		}
		else if (ancestor[node1][i] != 0) {
			lca = ancestor[node1][i];
		}
	}

	return lca;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	int node1, node2, root;
	cin >> t;
	for (int j = 0; j < t; j++) {
		cin >> n;

		for (int i = 0; i < n - 1; i++) {
			cin >> node1 >> node2;
			tree[node1].push_back(node2);
			tree[node2].push_back(node1);

			checkRoot[node2] = true;
		}

		for (int i = 1; i <= n; i++) {
			if (!checkRoot[i]) {
				root = i;
				break;
			}
		}

		depth[0] = -1;
		MakeArrays(root, 0);

		cin >> node1 >> node2;
		cout << FindLCA(node1, node2) << "\n";

		memset(depth, 0, sizeof(depth));
		memset(ancestor, 0, sizeof(ancestor[0][0]) * 10001 * 15);
		memset(checkRoot, false, sizeof(checkRoot));
		for (int i = 1; i <= n; i++) {
			tree[i].clear();
		}
	}
}