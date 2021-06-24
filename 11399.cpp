#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int sol[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, p, ans = 0;
	cin >> n;
	vector<int> v(n+1);	
	for (int i = 1; i <= n; i++) {
		cin >> p;
		v[i] = p;		
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <=n; i++) {
		v[i] = v[i - 1] + v[i];
		ans += v[i];
	}
	cout << ans;
}