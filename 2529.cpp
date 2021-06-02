#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(vector<char> c, vector<int> k) {
	for (int i = 0; i < c.size(); i++) {
		if (c[i] == '<' && k[i] > k[i + 1]) {
			return false;
		}
		if (c[i] == '>' && k[i] < k[i + 1]) {
			return false;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<char> inequality;
	vector<int> vBig;
	vector<int> vSmall;
	char c;
	for (int i = 0; i < n; i++) {
		cin >> c;
		inequality.push_back(c);
	}
	for (int i = 0; i <= n; i++) {
		vSmall.push_back(i);
		vBig.push_back(9 - i);
	}	
	
	do {
		if (check(inequality, vSmall)) {
			break;
		}		
	} while (next_permutation(vSmall.begin(), vSmall.end()));

	do {
		if (check(inequality, vBig)) {
			break;
		}
	} while (prev_permutation(vBig.begin(), vBig.end()));

	for (int i = 0; i < vBig.size(); i++) {
		cout << vBig[i];
	}
	cout << "\n";
	for (int i = 0; i < vSmall.size(); i++) {
		cout << vSmall[i];
	}
	cout << "\n";
}