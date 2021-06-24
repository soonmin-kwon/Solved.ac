#include<iostream>
using namespace std;

bool map[128][128];
int sol[2];
void Recursion(int x, int y, int size) {
	if (size == 1) {
		sol[map[y][x]] += 1;
		return;
	}
	bool check = true;
	bool temp = map[y][x];
	for (int i = y; i < y+size; i++) {
		for (int j = x; j < x+size; j++) {
			if (map[i][j] != temp) {
				check = false;
				Recursion(x, y, size / 2);
				Recursion(x+size/2, y, size / 2);
				Recursion(x, y + size / 2, size / 2);
				Recursion(x + size / 2, y + size / 2, size / 2);
				return;
			}
		}		
	}	
	sol[temp] += 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	Recursion(0, 0, n);
	cout << sol[0] << "\n";
	cout << sol[1];
}