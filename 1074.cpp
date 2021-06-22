#include<iostream>
using namespace std;

int n, r, c;
int ans;

void Recursion(int x, int y, int size) {
	if (c == x && r == y) {		
		cout << ans << "\n";
		return;
	}
	if (r >= y && r < y + size && c >= x && c < x + size) {
		Recursion(x, y, size / 2);
		Recursion(x+size/2, y, size / 2);
		Recursion(x, y + size / 2, size / 2);
		Recursion(x + size / 2, y + size / 2, size / 2);
	}
	else {
		ans += size * size;
	}
}

int main() {
	cin >> n >> r >> c;		
	Recursion(0, 0, (1 << n));
}