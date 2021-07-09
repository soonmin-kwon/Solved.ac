#include<iostream>
using namespace std;

int n, ans = 0;
int chess[15];

bool Check(int row) {
	for (int i = 0; i < row; i++) {
		if (chess[i] == chess[row] || abs(chess[row] - chess[i]) == row - i) {
			return false;
		}
	}
	return true;
}

void NQueen(int row) {
	if (n == row) {
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		chess[row] = i;
		if (Check(row)) {
			NQueen(row + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	NQueen(0);
	cout << ans;
}