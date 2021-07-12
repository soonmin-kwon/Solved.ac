#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int dist[20001];
vector<pair<int, int>> graph[20001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int vertex, edge, k, u, v, w;

	cin >> vertex >> edge;
	cin >> k;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 1; i <= vertex; i++) {
		dist[i] = 987654321;
	}

	dist[k] = 0;
	pq.push(make_pair(dist[k], k));

	for (int i = 0; i < edge; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(w, v));
	}

	while (!pq.empty()) {
		pair<int, int> node = pq.top();
		pq.pop();
		int distance = node.first;
		int ver = node.second;

		if (dist[ver] != distance) {
			continue;
		}

		for (int i = 0; i < graph[ver].size(); i++) {
			int weight = graph[ver][i].first;
			int next = graph[ver][i].second;

			int sum = distance + weight;

			if (sum < dist[next]) {
				dist[next] = sum;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	for (int i = 1; i <= vertex; i++) {
		if (dist[i] == 987654321) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}
}