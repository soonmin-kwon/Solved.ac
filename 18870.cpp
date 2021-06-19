#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool Compare(pair<int, int> a, pair<int, int>b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, p;
	vector<pair<int,int>> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		v.push_back(make_pair(i, p));
	}
	vector<int>v2(v.size(), 0);
	sort(v.begin(), v.end(), Compare);

	int temp = v[0].second;
	v2[v[0].first] = 0;
	int ansTemp = 0;
	for (int i = 1; i < v.size(); i++) {		
		if (temp != v[i].second) {			
			temp = v[i].second;
			ansTemp++;
			v2[v[i].first] = ansTemp;
		}
		else {			
			v2[v[i].first] = ansTemp;
		}
	}

	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}	
}