#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

bool visitied[10001];
vector<pair<int, int>> v[10001];

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

	for (int i = 0; i < n-1; i++) {
		cin >> parent >> child >> weight;
		v[parent].push_back(make_pair(child, weight));
		v[child].push_back(make_pair(parent, weight));
	}
	
	DFS(1, 0);
	memset(visitied, false, sizeof(visitied));
	DFS(endPoint, 0);
	cout << diameter;
}