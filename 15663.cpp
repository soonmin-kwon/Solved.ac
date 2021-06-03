#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> v;
	set<vector<int>> s;
	int n, m;
	cin >> n >> m;
	
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);		
	}
	sort(v.begin(), v.end());
	vector<bool> v2(n, false);	
	for (int i = 0; i < m; i++) {
		v2[i] = true;
	}	

	do {
		do {
			vector <int> temp;
			for (int i = 0; i < n; i++) {
				
				if (v2[i]) {
					temp.push_back(v[i]);
				}
			}			
			s.insert(temp);
		} while (prev_permutation(v2.begin(), v2.end()));
	} while (next_permutation(v.begin(), v.end()));

	for (auto it = s.begin(); it != s.end(); it++) {
		for (int i = 0; i < it->size(); i++) {
			cout << it->at(i) << " ";
		}

		cout << "\n";
	}
}