#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void hanoi(int start, int mid, int end, int n) {
	if (n == 1) {
		cout << start << " " << end << "\n";
	}
	else {
		hanoi(start, end, mid, n - 1);
		cout << start << " " << end << "\n";
		hanoi(mid, start, end, n - 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	string s = to_string(pow(2, n));	
	int idx = s.find('.');	
	s = s.substr(0, idx);	
	s[s.length() - 1] -= 1;
	cout << s << "\n";
	if (n <= 20) {
		hanoi(1, 2, 3, n);
	}	
	
}