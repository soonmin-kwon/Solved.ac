#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<pair<int, pair<int, int>>> v;
	int sol[26] = { 0, };
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,answer;
	cin >> n;
	int s, e, m;
	for (int i = 0; i < n; i++) {
		cin >> s >> e >> m;
		v.push_back(make_pair(m, make_pair(s, e)));
		sol[i] = v[i].first;
	}
	if (n == 1) {
		cout << sol[0] << "\n";
		return 0 ;
	}
	answer = max(sol[0], sol[1]);
	for (int i = 2; i < v.size(); i++) {		
		for (int j =0; j <i-1; j++) {			
			sol[i] = max(sol[i], v[i].first + sol[j]);
		}
		answer = max(answer, sol[i]);
	}
	
	cout << answer << "\n";
}