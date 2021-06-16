#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int n, m;
int sol[8];
set<vector<int>>s;
void Recur(vector<int> v, int cur, int count, vector<int> t) {
	t.push_back(v[cur]);
	if (count == m) {
		s.insert(t);
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		Recur(v, i, count + 1, t);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vector<int> v;
	vector<int> t;
	int p;
	for (int i = 0; i < n; i++) {
		cin >> p;
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		Recur(v, i, 1,t);
	}
	for (auto it = s.begin(); it != s.end(); it++) {
		for (int i = 0; i < it->size(); i++) {
			cout << it->at(i) << " ";
		}
		cout << "\n";
	}
}