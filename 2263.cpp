#include<iostream>
using namespace std;

int inOrder[100001];
int postOrder[100001];
int index[100001];

void PrintPreOrder(int inS, int inE, int postS, int postE) {
	if (inS > inE || postS > postE) {
		return;
	}

	int root = index[postOrder[postE]];	
	int left = root - inS;
	int right = inE - root;
	cout << inOrder[root] << " ";

	PrintPreOrder(inS, root - 1, postS, postS + left - 1);
	PrintPreOrder(root + 1, inE, postS + left, postE - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> inOrder[i];
		index[inOrder[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		cin >> postOrder[i];
	}

	PrintPreOrder(1, n, 1, n);
}