#include<iostream>
#include<vector>
using namespace std;

vector<int> tree[50];

int n, del, ans = 0;

void DFS(int node) {
	if (node == del) {
		return;
	}

	if (tree[node].empty()) {
		ans++;
		return;
	}

	if (tree[node].size() == 1 && tree[node][0] == del) {
		ans++;
		return;
	}

	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] != del) {
			DFS(tree[node][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int parent, root;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> parent;
		if (parent != -1) {			
			tree[parent].push_back(i);
		}
		else {
			root = i;
		}
	}
	cin >> del;

	DFS(root);

	cout << ans;	
}