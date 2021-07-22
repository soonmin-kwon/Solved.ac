#include<iostream>
#include<algorithm>
using namespace std;

int coin[101];
int cost[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		cost[i] = 10001;
	}
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			cost[j] = min(cost[j], cost[j - coin[i]] + 1);
		}
	}

	if (cost[k] == 10001) {
		cout << -1;
	}
	else {
		cout << cost[k];
	}
}