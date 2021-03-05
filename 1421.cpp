#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long int len[10001] = { 0, };

int main() {
	vector<long long int> tree;
	long long int n, c, w;
	int l;
	cin >> n >> c >> w;

	for (int i = 0; i < n; i++) {
		cin >> l;
		tree.push_back(l);
	}
	sort(tree.begin(), tree.end(), greater<int>());
	
	for (int i = 1; i <= tree.front(); i++) {
		for (int j = 0; j < tree.size(); j++) {
			if (tree[j] % i == 0) {
				if (((tree[j] / i) - 1) * c <= (tree[j] / i) * w*i) {
					len[i] += ((tree[j] / i) * w * i) - (((tree[j] / i) - 1) * c);
				}				
			}
			else {
				if (((tree[j] / i) ) * c <= (tree[j] / i) * w *i) {
					len[i] += ((tree[j] / i) * w * i) - ((tree[j] / i) * c);
				}				
			}			
		}
	}
	long long temp = len[1];
	for (int i = 1; i <= tree.front(); i++) {		
		if (temp < len[i]) {
			temp = len[i];
		}
	}
	cout << temp << endl;
}