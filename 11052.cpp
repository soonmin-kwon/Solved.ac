#include<iostream>
#include<algorithm>
using namespace std;

int card[1001];
int cost[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, p;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p;
		card[i] = p;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cost[i] = max(cost[i], cost[i - j] + card[j]);
		}
	}
	cout << cost[n];
}