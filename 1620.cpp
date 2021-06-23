#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	string s;
	map<string, int> map;
	string* strArr = new string[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> s;
		map[s] = i;
		strArr[i] = s;
	}
	string p;
	for (int i = 0; i < m; i++) {
		cin >> p;
		if (p[0] - '0' >=0 && p[0] - '0' <= 9) {
			cout << strArr[stoi(p)] << "\n";
			continue;
		}
		cout << map.find(p)->second << "\n";
	}
}