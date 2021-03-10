#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int h[21] = { -1, };
int p[21] = { -1, };

bool Compare(pair<int, int> a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}	
}

int main() {
	int n, k;
	int c;
	cin >>  k;
	int hs = 0;
	int solve = 0;
	n = 0;
	vector<pair<int, int>> sol;
	for (int i = 1; i <= k; i++) {
		cin >> c;
		h[i] = c;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c;
		p[i] = c;
	}	

	for (int i = 1; i <= k; i++) {
		sol.push_back(make_pair(h[i], p[i]));
	}

	while (true) {
		hs += sol[n].first;
		if (hs >= 100) {
			break;
		}

		solve += sol[n].second;
		n++;
	}
	cout << solve << endl;
}