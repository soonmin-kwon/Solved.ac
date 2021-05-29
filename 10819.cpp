#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, inp;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inp;
		v.push_back(inp);
	}
	sort(v.begin(), v.end());
	int answer = 0;
	do {
		int temp = 0;
		for (int i = 2; i <= n; i++) {
			temp += abs(v[i - 2] - v[i - 1]);
			answer = max(temp, answer);
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << answer << "\n";
}