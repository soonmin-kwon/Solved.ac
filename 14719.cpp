#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m;	
	cin >> n >> m;
	vector<int> rain;
	int inp;
	for (int i = 0; i < m; i++) {
		cin >> inp;
		rain.push_back(inp);
	}

	if (rain.empty()) {
		return 0;
	}
	int ans = 0;
	int size = rain.size();
	vector<int> leftMax(size), rightMax(size);
	leftMax[0] = rain[0];
	for (int i = 1; i < size; i++) {
		leftMax[i] = max(rain[i], leftMax[i - 1]);
	}
	rightMax[size - 1] = rain[size - 1];
	for (int i = size - 2; i >= 0; i--) {
		rightMax[i] = max(rain[i], rightMax[i + 1]);
	}
	for (int i = 1; i < size - 1; i++) {
		ans += min(leftMax[i], rightMax[i]) - rain[i];
	}
	cout << ans << endl;
}