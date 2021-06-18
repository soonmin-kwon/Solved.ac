#include<iostream>
using namespace std;

int paper[2188][2188];
int sol[3] = {};

void count(int x, int y, int n) {
	int temp = paper[x][y];
	bool cut = false;

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (temp != paper[i][j]) {
				cut = true;
				break;
			}
		}
	}

	if (cut) {
		for (int i = x; i < x + n; i+=n/3) {
			for (int j = y; j < y + n; j+=n/3) {
				count(i, j, n / 3);
			}
		}
	}
	else {
		sol[temp + 1] ++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	count(0, 0, n);
	for (int i = 0; i < 3; i++) {
		cout << sol[i] << "\n";
	}
}