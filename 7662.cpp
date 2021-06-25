#include<iostream>
#include<set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, k, n;
	char op;
	cin >> t;	
	for (int j = 0; j < t; j++) {
		cin >> k;
		multiset<int> queue;
		for (int i = 0; i < k; i++) {
			cin >> op >> n;
			if (op == 'I') {
				queue.insert(n);				
			}
			if (op == 'D' && !queue.empty()) {
				if (n == 1) {
					queue.erase(--queue.end());
				}
				else {
					queue.erase(queue.begin());
				}
			}
		}
		if (queue.empty()) {
			cout << "EMPTY" << "\n";
		}
		else {
			auto iterF = --queue.end();
			auto iterL = queue.begin();
			cout <<  *iterF << " " << *iterL << "\n";
		}
	}
}