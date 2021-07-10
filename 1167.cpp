#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool visitied[100001];
vector<pair<int, int>> v[100001];

int diameter = 0;
int endPoint = 0;

void DFS(int node, int weight) {
	visitied[node] = true;

	if (diameter < weight) {
		diameter = weight;
		endPoint = node;
	}

	int len = v[node].size();

	for (int i = 0; i < len; i++) {
		if (!visitied[v[node][i].first]) {
			DFS(v[node][i].first, weight + v[node][i].second);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int parent, child, weight;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> parent;

		while (1) {
			cin >> child;
			if (child == -1) {
				break;
			}
			cin >> weight;
			v[parent].push_back(make_pair(child, weight));
		}
	}

	DFS(1, 0);
	memset(visitied, false, sizeof(visitied));
	DFS(endPoint, 0);
	cout << diameter;
}