#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	int t, n, cntR, cntD;
	string p, arr;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> p >> n >> arr;
		list<int> l;
		cntR = 0, cntD = 0;
		string temp="";
		
		for (int j = 0; j < arr.size(); j++) {
			if (arr[j] - '0' >= 0 && arr[j] - '0' <= 9) {
				temp += arr[j];
			}
			if (arr[j] == ',' || arr[j] == ']') {
				if (temp.size() != 0) {
					l.push_back(stoi(temp));
				}				
				temp = "";
			}
		}		
		int times = 0;
		bool error = false;
		for (int k = 0; k < p.size(); k++) {
			if (p[k] == 'R') {
				times++;
			}
			if (p[k] == 'D') {
				if (l.empty()) {
					cout << "error" << "\n";
					error = true;
					break;
				}
				if (times % 2 != 0) {					
					l.pop_back();
				}
				else {					
					l.pop_front();
				}
			}
		}
		if (error) {
			continue;
		}
		else if(l.empty()){
			cout << "[]"<<"\n";
			continue;
		}
		vector<int> v(l.begin(), l.end());
		cout << "[";
		if (times % 2 == 0) {
			for (int a = 0; a < v.size() - 1; a++) {
				cout << v[a] << ",";
			}
			cout << v[v.size() - 1];
		}
		else {
			for (int a = v.size() - 1; a >= 1; a--) {
				cout << v[a] << ",";
			}
			cout << v[0];
		}

		cout << "]" << "\n";
	}
}