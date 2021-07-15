#include<iostream>
#include<algorithm>
using namespace std;

int tree[10001][2];
int minimum[10001];
int maximum[10001];
int cnt[10001];
int order = 1;

void InOrder(int root, int lev) {
	if (tree[root][0] != -1) {
		InOrder(tree[root][0], lev + 1);
	}	
	
	minimum[lev] = min(minimum[lev], order);
	maximum[lev] = max(maximum[lev], order++);

	if (tree[root][1] != -1) {
		InOrder(tree[root][1], lev + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, node, leftChild, rightChild;
	int root, width, lev;

	cin >> n;
	
	for (int i = 0; i <= n; i++) {
		minimum[i] = 987654321;
	}

	for (int i = 0; i < n; i++) {
		cin >> node >> leftChild >> rightChild;
		tree[node][0] = leftChild;
		tree[node][1] = rightChild;
		cnt[node]+=1;
		if (leftChild != -1) {
			cnt[leftChild] += 1;
		}
		if (rightChild != -1) {
			cnt[rightChild] += 1;
		}		
	}
	
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 1) {
			root = i;
			break;
		}
	}

	InOrder(root, 1);

	width = maximum[1] - minimum[1] + 1;
	lev = 1;

	for (int i = 2; i <= n; i++) {
		int temp = maximum[i] - minimum[i] + 1;
		if (width < temp) {
			width = temp;
			lev = i;
		}
	}
	cout << lev << " " << width;
}