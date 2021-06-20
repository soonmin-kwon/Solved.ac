#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[100001];
bool visitied[100001];
vector<int> v[100001];

void FindParent(int x) {
	visitied[x] = true;

	for (int i = 0; i < v[x].size(); i++) {
		if (!visitied[v[x][i]]) {
			parent[v[x][i]] = x;
			FindParent(v[x][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nc, n1, n2;
	
	cin >> nc;

	for (int i = 1; i < nc; i++) {
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}
	FindParent(1);
	for (int i = 2; i <= nc; i++) {
		cout << parent[i] << "\n";
	}
}