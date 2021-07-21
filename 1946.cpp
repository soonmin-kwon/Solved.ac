#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	int docu, interview;
	int rank, ans;
	cin >> t;
	for (int j = 0; j < t; j++) {
		cin >> n;
		vector<pair<int, int>> v;

		for (int i = 0; i < n; i++) {
			cin >> docu >> interview;
			v.push_back(make_pair(docu, interview));
		}

		sort(v.begin(), v.end());
		rank = v[0].second;
		ans = 1;

		for (int i = 1; i < n; i++) {
			if (v[i].second < rank) {
				ans++;
				rank = v[i].second;
			}
		}

		cout << ans << "\n";
	}
}