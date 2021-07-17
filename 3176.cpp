#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> tree[100001];
int distMin[100001][17];
int distMax[100001][17];
int ancestor[100001][17];
int depth[100001];

void MakeArrays(int cur, int parent, int dist) {
	depth[cur] = depth[parent] + 1;

	ancestor[cur][0] = parent;
	distMin[cur][0] = dist;
	distMax[cur][0] = dist;

	for (int i = 1; i <= 16; i++) {
		ancestor[cur][i] = ancestor[ancestor[cur][i - 1]][i - 1];
		distMin[cur][i] = min(distMin[cur][i - 1], distMin[ancestor[cur][i - 1]][i - 1]);
		distMax[cur][i] = max(distMax[cur][i - 1], distMax[ancestor[cur][i - 1]][i - 1]);
	}

	int len = tree[cur].size();
	for (int i = 0; i < len; i++) {
		int child = tree[cur][i].first;
		int dist = tree[cur][i].second;

		if (child != parent) {
			MakeArrays(child, cur, dist);
		}
	}
}

pair<int,int> FindDistances(int node1, int node2) {
	int minDist = 987654321;
	int maxDist = 0;

	if (depth[node1] != depth[node2]) {
		if (depth[node1] > depth[node2]) {
			int temp = node1;
			node1 = node2;
			node2 = temp;
		}

		for (int i = 16; i >= 0; i--) {
			if (depth[node1] <= depth[ancestor[node2][i]]) {
				minDist = min(minDist, distMin[node2][i]);
				maxDist = max(maxDist, distMax[node2][i]);
				node2 = ancestor[node2][i];
			}
		}
	}

	if (node1 == node2) {
		if (minDist != 987654321) {
			return pair<int, int>(minDist, maxDist);
		}
		else {
			return pair<int, int>(0, 0);
		}		
	}

	int lca = node1;

	for (int i = 16; i >= 0; i--) {
		if (ancestor[node1][i] != ancestor[node2][i]) {
			minDist = min(minDist,min(distMin[node1][i], distMin[node2][i]));
			maxDist = max(maxDist, max(distMax[node1][i], distMax[node2][i]));

			node1 = ancestor[node1][i];
			node2 = ancestor[node2][i];
		}		
	}
	minDist = min(minDist, min(distMin[node1][0], distMin[node2][0]));
	maxDist = max(maxDist, max(distMax[node1][0], distMax[node2][0]));	

	return pair<int, int>(minDist, maxDist);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, node1, node2, road;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> node1 >> node2 >> road;
		tree[node1].push_back(make_pair(node2, road));
		tree[node2].push_back(make_pair(node1, road));
	}

	depth[0] = -1;
	MakeArrays(1, 0, 0);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2;
		cout << FindDistances(node1, node2).first << " " << FindDistances(node1, node2).second << "\n";
	}
}