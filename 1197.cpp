#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[10001];
int FindParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = FindParent(parent[x]);
	}
}
bool SameParent(int x, int y) {
	x = FindParent(x);
	y = FindParent(y);
	if (x == y) {
		return true;
	}
	else {
		return false;
	}
}
void Union(int x, int y) {
	x = FindParent(x);
	y = FindParent(y);
	if (x != y) {
		parent[y] = x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, pair<int, int>>> v;
	int answer = 0;
	int vertex, e;
	cin >> vertex >> e;
	int vtx1, vtx2, cost;
	for (int i = 1; i <= vertex; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < e; i++) {
		cin >> vtx1 >> vtx2 >> cost;
		v.push_back(make_pair(cost, make_pair(vtx1, vtx2)));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < e; i++) {
		if (!SameParent(v[i].second.first, v[i].second.second)) {
			Union(v[i].second.first, v[i].second.second);
			answer += v[i].first;
		}
	}
	cout << answer << "\n";
}