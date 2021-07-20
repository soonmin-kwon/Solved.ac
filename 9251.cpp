#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int lcs[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a >> b;

	int len1 = a.size();
	int len2 = b.size();

	int ans = 0;

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (b[j-1] != a[i-1]) {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
				ans = max(ans, lcs[i][j]);
			}
			else if (b[j - 1] == a[i - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
				ans = max(ans, lcs[i][j]);
			}			
		}
	}

	cout << ans;
}