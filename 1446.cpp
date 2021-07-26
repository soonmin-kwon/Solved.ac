#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<pair<int, int>> v[10001];
int dist[10001];
int n, d;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start, end, dis, prev;
	cin >> n >> d;

	for (int i = 0; i <= d; i++) {
		dist[i] = i;
	}

	for (int i = 0; i < n; i++) {
		cin >> start >> end >> dis;
		if (end > d) {
			continue;
		}

		if (dis >= end - start) {
			continue;
		}

		v[start].push_back(make_pair(dis, end));
	}	
	
	for (int i = 0; i <= d; i++) {
		if (i != 0) {
			dist[i] = min(dist[i], dist[i - 1] + 1);
		}

		if (!v[i].empty()) {
			int len = v[i].size();
			for (int j = 0; j < len; j++) {
				int distance = v[i][j].first;
				int vertex = v[i][j].second;

				dist[vertex] = min(dist[i] + distance, dist[vertex]);
			}
		}
	}

	cout << dist[d];
}