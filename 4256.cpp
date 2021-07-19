#include<iostream>
#include<vector>
using namespace std;

int preOrder[1001];
int inOrder[1001];
int rootIndex[1001];
int preIndex[1001];

void PostOrder(int left, int right, int root) {
	if (left == right) {
		cout << root << " ";
		return;
	}

	int leftSize = rootIndex[root] - left;	

	if (rootIndex[root] - 1 >= left) {
		PostOrder(left, left + leftSize - 1, preOrder[preIndex[root]+1]);
	}

	if (rootIndex[root] + 1 <= right) {
		PostOrder(left + leftSize + 1, right, preOrder[preIndex[root] + leftSize + 1 ]);
	}

	cout << root << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t; 
	for (int k = 0; k < t; k++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> preOrder[i];
			preIndex[preOrder[i]] = i;
		}

		for (int i = 1; i <= n; i++) {
			cin >> inOrder[i];
			rootIndex[inOrder[i]] = i;
		}

		PostOrder(1, n, preOrder[1]);
		cout << "\n";
	}
}