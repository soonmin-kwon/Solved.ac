#include <iostream>
using namespace std;

int main() {

	int pas[31][31];

	for (int i = 1; i <= 30; i++) {
		pas[i][1] = 1;
	}

	for (int i = 2; i <= 30; i++) {
		pas[i][i] = 1;
	}

	for (int i = 3; i <= 30; i++) {
		for (int j = 2; j < i; j++) {
			pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
		}
	}

	int n, k;
	cin >> n >> k;

	cout << pas[n][k];
}