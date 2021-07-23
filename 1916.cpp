#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int, int>> graph[1001];
int dist[1001];

void Dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[start] = 0;
	pq.push(make_pair(dist[start], start));

	while (!pq.empty()) {
		pair<int, int> node = pq.top();
		pq.pop();

		int distance = node.first;
		int vertex = node.second;

		if (dist[vertex] < distance) {
			continue;
		}

		int len = graph[vertex].size();

		for (int i = 0; i < len; i++) {
			int weight = graph[vertex][i].second;
			int next = graph[vertex][i].first;

			int sum = distance + weight;

			if (sum < dist[next]) {
				dist[next] = sum;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int start, dest, cost;	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		dist[i] = 1111111111;
	}
	
	for (int i = 0; i < m; i++) {
		cin >> start >> dest >> cost;
		graph[start].push_back(make_pair(dest, cost));
	}

	cin >> start >> dest;
	Dijkstra(start);

	cout << dist[dest];
}