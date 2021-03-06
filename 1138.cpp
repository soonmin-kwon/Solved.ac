#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

bool Compare(pair<int,int> a, pair<int,int> b){
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}	
}

int main() {

	vector<pair<int, int>> data;
	vector <int> solve;
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		data.push_back(make_pair(i+1, k));
	}
	sort(data.begin(), data.end(), Compare );

	for (int i = 0; i < n; i++) {
		if (data[i].second == 0) {
			data[i].second -= 1;
			solve.push_back(data[i].first);
			for (int j = i+1; j < n; j++) {
				if (data[i].first > data[j].first) {
					data[j].second -= 1;
				}
			}
			sort(data.begin(), data.end(), Compare);
		}
	}

	for (int i = 0; i < solve.size(); i++) {
		cout << solve[i] << " ";
	}
	cout << endl;
}