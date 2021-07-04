#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int prob[59][59];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	
	int n, ans = 0;
	char p1, p2;
	string arrow;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p1 >> arrow >> p2;
		prob[p1 - 'A' + 1][p2 - 'A' + 1] = 1;
	}
	for (int i = 1; i <= 58; i++) {
		for (int j = 1; j <= 58; j++) {
			for (int k = 1; k <= 58; k++) {
				if (j == k) {
					continue;
				}
				if (prob[j][i] != 0 && prob[i][k] != 0) {
					if (prob[j][k] == 0) {
						prob[j][k] = prob[i][k] + prob[j][i];
					}
					else {
						prob[j][k] = min(prob[j][i] + prob[i][k], prob[j][k]);
					}
				}
			}
		}
	}
	
	for (int i = 1; i <= 58; i++) {
		for (int j = 1; j <= 58; j++) {
			if (prob[i][j] != 0 && i!=j) {
				ans++;
			}
		}
	}
	cout << ans << "\n";

	for (int i = 1; i <= 58; i++) {
		for (int j = 1; j <= 58; j++) {
			if (prob[i][j] != 0 && i!=j) {
				cout << (char)(i + 64) << " " + arrow +" " << (char)(j + 64) << "\n";
			}
		}		
	}
}