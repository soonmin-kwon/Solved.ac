#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool Compare(pair<int, int>a, pair<int, int>b) {
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, l, h;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		cin >> l >> h;
		v.push_back(make_pair(l, h));
	}
	sort(v.begin(), v.end());

	pair<int,int> max = *max_element(v.begin(), v.end(), [](const auto& lhs, const auto& rhs) {
		return lhs.second < rhs.second;
		});
	
	int ans = max.second;	
	int startL = v[0].first;
	int startH = v[0].second;
	for (int i = 0; i < v.size(); i++) {
		if (startH <= v[i].second) {
			ans += (v[i].first - startL) * startH;			
			startL = v[i].first;
			startH = v[i].second;
			if (v[i].first == max.first) {
				break;
			}
		}
	}

	int endL = v[v.size() - 1].first;
	int endH = v[v.size() - 1].second;
	for (int i = v.size() - 2; i >= 0; i--) {
		if (endH <= v[i].second) {
			ans += (endL - v[i].first) * endH;			
			endL = v[i].first;
			endH = v[i].second;
			if (v[i].first == max.first) {
				break;
			}
		}
	}
	cout << ans;
}