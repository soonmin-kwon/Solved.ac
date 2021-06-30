#include<queue>
#include<vector>
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, card;
	long long ans = 0;
	cin >> n >> m;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < n; i++) {
		cin >> card;
		pq.push(card);
	}

	for (int i = 0; i < m; i++) {
		long long small1 = pq.top();
		pq.pop();
		long long small2 = pq.top();
		pq.pop();
		long long sum = small1 + small2;
		pq.push(sum);
		pq.push(sum);
	}

	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans << "\n";
}