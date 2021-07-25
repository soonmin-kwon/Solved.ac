#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int length;
bool breakdown[10];

bool isPossible(int butt) {	
	if (butt == 0) {
		if (breakdown[0]) {
			return false;
		}
		else {
			return true;
		}
	}

	while (butt) {
		if (breakdown[butt % 10]) {
			return false;
		}

		butt = butt / 10;		
	}

	return true;
}

int countButton(int n) {
	int countNonNumButton = abs(n - 100);
	int ans = 987654321;
	int temp;
	for (int i = 0; i < 1000001; i++) {		
		if (isPossible(i)) {		
			temp = to_string(i).length() + abs(n - i);
			ans = min(ans, temp);
		}
	}

	return min(ans, countNonNumButton);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	int n, m, button;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> button;
		breakdown[button] = true;
	}

	cout << countButton(n);
}