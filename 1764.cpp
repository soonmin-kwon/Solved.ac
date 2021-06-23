#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, ans=0;
	string s;
	cin >> n >> m;
	map<string, bool> map, mapS;
	vector<string> v;

	for (int i = 0; i < n; i++) {
		cin >> s;
		map[s] = true;		
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		if (map.find(s) != map.end()) {
			if (map.find(s)->second) {
				ans++;
				v.push_back(s);
			}
		}
	}	
	sort(v.begin(), v.end());
	cout << ans << "\n";	
		
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}