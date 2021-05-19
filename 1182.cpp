#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, s, input;
	int answer = 0;
	vector<int> v;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		vector<bool> temp(n,false);
		for (int j = 0; j <= i; j++) {
			temp[j] = true;
		}
		do {
			int sum = 0;
			for (int k = 0; k < n; k++) {
				if (temp[k]) {
					sum += v[k];
				}
			}
			if (sum == s) {
				answer++;
			}
		} while (prev_permutation(temp.begin(), temp.end()));
	}
	cout << answer << endl;
	
}