#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[100001];
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
	int computer, e;
	cin >> computer >> e;
	int cpt1, cpt2, cost;
	for (int i = 1; i <= computer; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < e; i++) {
		cin >> cpt1 >> cpt2 >> cost;
		v.push_back(make_pair(cost, make_pair(cpt1, cpt2)));
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