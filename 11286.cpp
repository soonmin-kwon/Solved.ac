#include<queue>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Compare {
public:
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		else {
			return abs(a) > abs(b);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int, vector<int>, Compare> pq;
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(k);
		}
	}
}