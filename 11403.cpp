#include<iostream>
#include<algorithm>
using namespace std;

int graph[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				
				if (graph[j][i] != 0 && graph[i][k] != 0) {
					if (graph[j][k] == 0) {
						graph[j][k] = graph[j][i] + graph[i][k];
					}
					else {
						graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
					}
				}
			}
		}
	}	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] != 0) {
				cout << 1 << " ";
				continue;
			}
			cout << 0 << " ";
		}
		cout << "\n";
	}
}