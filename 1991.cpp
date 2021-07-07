#include<map>
#include<iostream>
using namespace std;

map<char, pair<char, char>> tree;

void Preorder(char node) {
	cout << node;
	if (tree[node].first != '.') {
		Preorder(tree[node].first);
	}
	if (tree[node].second != '.') {
		Preorder(tree[node].second);
	}
}

void Inorder(char node) {
	if (tree[node].first != '.') {
		Inorder(tree[node].first);
	}
	cout << node;
	if (tree[node].second != '.') {
		Inorder(tree[node].second);
	}
}

void Postorder(char node) {
	if (tree[node].first != '.') {
		Postorder(tree[node].first);
	}	
	if (tree[node].second != '.') {
		Postorder(tree[node].second);
	}
	cout << node;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	int n;
	cin >> n;
	char parent, childL, childR;
	for (int i = 0; i < n; i++) {
		cin >> parent >> childL >> childR;
		tree[parent] = make_pair(childL, childR);
	}

	Preorder('A');
	cout << "\n";
	Inorder('A');
	cout << "\n";
	Postorder('A');
}