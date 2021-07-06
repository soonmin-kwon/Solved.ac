#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long int x, y, center = 0, move = 0, remain = 0, quot = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {		
		cin >> x >> y;
		center = 0;
		while (center * center <= y - x) {
			center++;
		}
		center--;
		move = 2 * center - 1;
		remain = y - x - center * center;
		quot = remain / center;
		move += quot;
		if (remain % center != 0) {
			move++;
		}		
		cout << move << "\n";
	}
}