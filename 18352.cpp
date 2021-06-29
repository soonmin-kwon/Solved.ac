#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> v[300001];
int cnt[300001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	int inp1, inp2;
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		cin >> inp1 >> inp2;
		v[inp1].push_back(inp2);
	}	
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int nX = q.front();		
		q.pop();
		if (cnt[nX] > k) {
			break;
		}
		for (int i = 0; i < v[nX].size(); i++) {
			int y = v[nX][i];
			if (cnt[y] == 0 && y != x) {
				cnt[y] = cnt[nX] + 1;
				q.push(y);
				if (cnt[y] == k) {
					ans.push_back(y);
				}
			}
		}
	}
	if (ans.empty()) {
		cout << -1 <<"\n";
		return 0;
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}