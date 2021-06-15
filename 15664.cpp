#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, p;
	cin >> n >> m;
	vector<bool> able(n, false);	
	vector<int> v;
	set<vector<int>> s;
	for (int i = 0; i < n; i++) {
		cin >> p;
		v.push_back(p);
	}		
	for (int i = 0; i < m; i++) {
		able[i] = true;
	}	
	sort(v.begin(), v.end());	
	
	do {
		vector<int> temp;
		for (int i = 0; i < n; i++) {
			if (able[i]) {
				temp.push_back(v[i]);
			}			
		}
		s.insert(temp);
	} while (prev_permutation(able.begin(), able.end()));

	for (auto it = s.begin(); it != s.end(); it++) {
		for (int i = 0; i < it->size(); i++) {
			cout << it->at(i) << " ";
		}
		cout << "\n";
	}
}