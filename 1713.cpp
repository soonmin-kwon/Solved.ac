#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int k;

bool Compare(pair<int, pair<int,int>> a, pair<int, pair<int,int>>b) {
	if (a.first == b.first) {
		return a.second.first > b.second.first;
	}
	return a.first > b.first;	
}

bool Compare2(pair<int, pair<int, int>> a, pair<int, pair<int, int>>b) {	
	return a.second.second < b.second.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
		
	vector<pair<int, pair<int,int>>> picture;
	for (int i = 0; i < m; i++) {
		cin >> k;
		auto it = find_if(picture.begin(), picture.end(), [](const pair<int, pair<int, int>>& pair) {
			return pair.second.second == k;
			});
		if (picture.size() != n && it == picture.end()) {
			picture.push_back(make_pair(1, make_pair(i, k)));
		}
		else {			
			if (it != picture.end()) {
				picture[it - picture.begin()].first++;
			}
			else {
				sort(picture.begin(), picture.end(),Compare);
				picture.pop_back();
				picture.push_back(make_pair(1, make_pair(i, k)));
			}
		}
	}
	sort(picture.begin(), picture.end(), Compare2);
	for (int i = 0; i < picture.size(); i++) {
		cout << picture[i].second.second << " ";
	}
}