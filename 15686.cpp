#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int map[51][51];
int dist[51][51];
bool visitied[51][51];
int n, m;

int Distance(pair<int,int> p1, pair<int,int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 987654321;
	cin >> n >> m;

	vector<pair<int, int>> chicken;
	vector<pair<int, int>> house;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	vector<bool> check(chicken.size(), false);

	int len = chicken.size();
	int len2 = house.size();

	for (int l = 1; l <= m; l++) {
		for (int i = 0; i < l; i++) {
			check[i] = true;
		}

		do {
			vector<int> dist(len2, 99999);

			int temp = 0;
			for (int i = 0; i < len; i++) {
				if (check[i]) {
					for (int j = 0; j < len2; j++) {
						dist[j] = min(dist[j], Distance(house[j], chicken[i]));
					}
				}
			}

			for (int i = 0; i < len2; i++) {
				temp += dist[i];
			}

			ans = min(ans, temp);
		} while (prev_permutation(check.begin(), check.end()));
	}

	cout << ans;
}