#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[100001];
int Find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = Find(parent[x]);
	}
}

bool SameParent(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) {
		return true;
	}
	else {
		return false;
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		parent[y] = x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, pair<int, int>>> v;
	int n, m;
	cin >> n >> m;
	int x, y, c;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> c;
		v.push_back(make_pair(c, make_pair(x, y)));
	}
	sort(v.begin(), v.end());
	vector<int> answer;
	for (int i = 0; i < m; i++) {
		if (!SameParent(v[i].second.first, v[i].second.second)) {
			Union(v[i].second.first, v[i].second.second);
			answer.push_back(v[i].first);
		}
	}
	int sol = 0;
	for (int i = 0; i < answer.size()-1 ; i++) {
		sol += answer[i];
	}
	cout << sol << "\n";
}