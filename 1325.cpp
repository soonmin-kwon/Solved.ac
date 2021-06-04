#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

vector<int> computer[10001];
bool visitied[10001];
int n, m;
int ans = 0;

void dfs(int j) {	
	visitied[j] = true;
	for (int i = 0; i < computer[j].size(); i++) {
		int next = computer[j][i];
		if (!visitied[next]) {			
			dfs(next);
			ans++;
		}				
	}	
}

int main() {		
	vector<pair <int, int>>v;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int inp1, inp2;
	for (int i = 0; i < m; i++) {
		cin >> inp1 >> inp2;		
		computer[inp2].push_back(inp1);
	}

	for (int i = 1; i <= n; i++) {
		dfs(i);
		memset(visitied, false, sizeof(visitied));
		v.push_back(make_pair(i, ans));
		ans = 0;
	}	
	int temp = -1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second > temp) {
			temp = v[i].second;
		}
	}	

	for (int i = 0; i < v.size(); i++) {
		if (temp == v[i].second) {
			cout << v[i].first << " ";
		}
	}
}