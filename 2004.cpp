#include<iostream>
#include<algorithm>
using namespace std;

int count(int n, int k) {
	int cnt=0;
	for (long long i = k; i <= n; i *= k) {
		cnt += n / i;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	int five = count(n, 5) - count(m, 5) - count(n - m, 5);
	int two = count(n, 2) - count(m, 2) - count(n - m, 2);

	cout << min(five, two) << "\n";
}