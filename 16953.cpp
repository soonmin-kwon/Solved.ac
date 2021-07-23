#include<iostream>
#include<queue>
using namespace std;

int a, b;

int BFS() {
	queue<pair<long long int, int>> q;

	q.push(make_pair(a,1));

	while (!q.empty()) {
		long long int top = q.front().first;
		int count = q.front().second;
		q.pop();

		if (top == b) {
			while (!q.empty()) {
				q.pop();
			}

			return count;
		}

		if (top > b) {			
			continue;
		}

		q.push(make_pair(top * 2, count + 1));
		q.push(make_pair((10 * top) + 1, count + 1));
	}

	return 0;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	if (BFS() == 0) {
		cout << -1;

		return 0;
	}

	cout << BFS();	
}