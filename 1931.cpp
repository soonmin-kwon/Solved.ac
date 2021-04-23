#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool Comp(pair<int, int> a, pair<int, int> b);

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n, count = 1;
	int inp1, inp2;
	cin >> n;
	vector<pair<int, int>> sol;
	for (int i = 0; i < n; i++) {
		cin >> inp1 >> inp2;
		sol.push_back(make_pair(inp1, inp2));
	}	
	sort(sol.begin(), sol.end(), Comp);
	int temp = sol[0].second;
	for (int i = 1; i < n; i++) {
		if (sol[i].first >= temp) {
			temp = sol[i].second;
			count++;
		}
	}
	cout << count << endl;
}

bool Comp(pair<int, int> a, pair<int, int> b) {
	
	if (a.second == b.second) {
		return a.first < b.first;
	}

	return a.second < b.second;
}