#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int n, m;
int sol[9];
void Recur(vector<int> v, int index, int count) {	
	sol[count] = v[index];
	if (count == m) {	
		for (int i = 1; i <=m; i++) {
			cout << sol[i] << " ";
		}
		cout << "\n";
		return;
	}	
	for (int i = 0; i < v.size(); i++) {		
		if (v[index] <= v[i]) {				
			Recur(v, i, count+1);
		}		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	set<int>s;
	int p;		
	cin >> n >> m;	
	for (int i = 0; i < n; i++) {
		cin >> p;
		s.insert(p);
	}
	vector<int>v(s.begin(), s.end());
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		Recur(v, i, 1);
	}
}