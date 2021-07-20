#include<iostream>
#include<vector>
using namespace std;

vector<int> tree[100001];
int countChildren[100001];

void MakeCountChildren(int root, int parent) {
	countChildren[root] = 1;

	int len = tree[root].size();	

	for (int i = 0; i < len; i++) {
		int child = tree[root][i];

		if (child != parent) {
			MakeCountChildren(child, root);

			countChildren[root] += countChildren[child];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, r, q;
	int u, v, query;
	cin >> n >> r >> q;

	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	MakeCountChildren(r, 0);

	for (int i = 0; i < q; i++) {
		cin >> query;
		cout << countChildren[query] << "\n";
	}
}