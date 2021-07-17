#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> tree[10001];
int people[10001];
int greatTown[10001][2]; // 0 = 우수 x, 1 = 우수 o

void CountPeople(int cur, int prev) {
	greatTown[cur][0] = 0;
	greatTown[cur][1] = people[cur];

	int len = tree[cur].size();

	for (int i = 0; i < len; i++) {
		int child = tree[cur][i];
		if (prev != child) {
			CountPeople(child, cur);

			greatTown[cur][0] += max(greatTown[child][0], greatTown[child][1]);
			greatTown[cur][1] += greatTown[child][0];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, node1, node2;	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> people[i];		
	}

	for (int i = 0; i < n - 1; i++) {
		cin >> node1 >> node2;
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	CountPeople(1, 0);

	cout << max(greatTown[1][0], greatTown[1][1]);
}