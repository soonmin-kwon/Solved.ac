#include <iostream>
#include <algorithm>
using namespace std;

int cost[1001][3];

int main() {

	int n;
	int c1, c2, c3;
	cin >> n;	
	cost[0][0] = 0;
	cost[0][1] = 0;
	cost[0][2] = 0;

	for (int i = 1; i <= n; i++) {

		cin >> c1 >> c2 >> c3;

		cost[i][0] = min(cost[i-1][1], cost[i-1][2]) + c1;
		cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + c2;
		cost[i][2] = min(cost[i - 1][1], cost[i - 1][0]) + c3;

	}
	cout << min(cost[n][0], min(cost[n][1], cost[n][2]));
}