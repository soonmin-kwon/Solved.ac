#include<iostream>
#include<vector>
using namespace std;

int tree[1000001][2];

void PostOrder(int node) {
	if (tree[node][0] != 0) {
		PostOrder(tree[node][0]);
	}

	if (tree[node][1] != 0) {
		PostOrder(tree[node][1]);
	}

	cout << node << "\n";
}

void MakeTree(int node, int root) {
	if (node < root) {
		if (tree[root][0] == 0) {
			tree[root][0] = node;
		}
		else {
			MakeTree(node, tree[root][0]);
		}
	}
	else {
		if (tree[root][1] == 0) {
			tree[root][1] = node;
		}
		else {
			MakeTree(node, tree[root][1]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int node;
	int root;

	cin >> root;

	while(true) {
		cin >> node;
		if (cin.eof()) {
			break;
		}

		MakeTree(node, root);
	}

	PostOrder(root);
}
