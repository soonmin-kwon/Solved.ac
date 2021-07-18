#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int edge[10001];
vector<int> answer;
int independent[10001][2];
vector<int> tree[10001];

void MakeIndependent(int cur, int parent) {
	independent[cur][0] = 0;
	independent[cur][1] = edge[cur];

	int len = tree[cur].size();
	for (int i = 0; i < len; i++) {
		int child = tree[cur][i];

		if (child != parent) {
			MakeIndependent(child, cur);
			
			independent[cur][0] += max(independent[child][1], independent[child][0]);
			independent[cur][1] += independent[child][0];			
		}
	}
}

void MakeAnswer(int cur, int parent, int state) {
	int len = tree[cur].size();

	if (state == 1) {
		answer.push_back(cur);

		for (int i = 0; i < len; i++) {
			int child = tree[cur][i];

			if (child != parent) {
				MakeAnswer(child, cur, 0);
			}
		}
	}
	else {
		for (int i = 0; i < len; i++) {
			int child = tree[cur][i];

			if (child != parent) {
				if (independent[child][0] < independent[child][1]) {
					MakeAnswer(child, cur, 1);
				}
				else {
					MakeAnswer(child, cur, 0);
				}
			}
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
		cin >> edge[i];
	}

	for (int i = 0; i < n - 1; i++) {
		cin >> node1 >> node2;
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}
	
	MakeIndependent(1, 0);
	cout << max(independent[1][0], independent[1][1]) << "\n";

	if (independent[1][0] > independent[1][1]) {
		MakeAnswer(1, 0, 0);
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
		return 0;
	}

	MakeAnswer(1, 0, 1);
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}
