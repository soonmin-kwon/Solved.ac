#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool Compare(pair<int, int> a, pair<int, int>b) {
	return a.second > b.second;
}

int main() {
	int w, b;
	int i = 1;
	vector<pair<int, int>> white;
	vector<pair<int, int>> black;
	cin >> w >> b;
	int sum = 0;
	if(w >= b) white.push_back(make_pair(i, w));
	else black.push_back(make_pair(i, b));
	
	while (scanf("%d %d", &w, &b) ==2) {
		sum = 0;		
		i++;		
		if (w >= b) {
			if (white.size() >= 15) {
				if (white.back().second < w) { 
					white.pop_back(); 
					white.push_back(make_pair(i, w));
				}
				else {
					if (black.back().second < b) {
						black.pop_back();
						black.push_back(make_pair(i, b));
					}
				}
			}
			else {
				white.push_back(make_pair(i, w));
			}			
		}
		else if (w < b) {
			if (black.size() >= 15) {
				if (black.back().second < b) {
					black.pop_back();
					black.push_back(make_pair(i, b));
				}
				else {
					if (white.back().second < w) {
						white.pop_back();
						white.push_back(make_pair(i, w));
					}
				}
			}		
			else {
				black.push_back(make_pair(i, b));
			}
		}		
		sort(white.begin(), white.end(), Compare);
		sort(black.begin(), black.end(), Compare);		
	}
	for (long unsigned int i = 0; i < white.size(); i++) {
		sum += white[i].second;
	}
	for (long unsigned int i = 0; i < black.size(); i++) {
		sum += black[i].second;
	}
	cout << sum << endl;
}