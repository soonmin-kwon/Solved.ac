#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knapsack[101][100001];
int weight[101];
int value[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	int ans = 0;
	cin >> n >> k;	

	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];		
	}

	for (int i = 1; i <= n; i++) {		
		for (int j = 1; j <= k; j++) {
			if (weight[i] <= j) {
				knapsack[i][j] = max(value[i] + knapsack[i-1][j-weight[i]], knapsack[i-1][j]);
			}
			else {
				knapsack[i][j] = knapsack[i-1][j];
			}

			ans = max(ans, knapsack[i][j]);
		}		
	}

	cout << ans;
}