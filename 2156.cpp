#include<iostream>
#include<algorithm>
using namespace std;

int cost[10001];
int tCost[10001];
int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	tCost[0] = cost[0] = 0;
	tCost[1] = cost[1];
	tCost[2] = cost[1] + cost[2];
	
	
	for (int i = 3; i <= n; i++) {
		tCost[i] = max(tCost[i - 3] + cost[i - 1] + cost[i], max(tCost[i - 2] + cost[i], tCost[i - 1]));
	}
	cout << tCost[n] << "\n";
}