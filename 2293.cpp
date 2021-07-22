#include<iostream>
#include<algorithm>
using namespace std;

int coin[101];
int cases[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	cases[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
		
		for (int j = coin[i] ; j <= k; j++) {
			cases[j] += cases[j - coin[i]];
		}
	}

	cout << cases[k];
}