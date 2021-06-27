#include<set>
#include<iostream>
#include<string>
using namespace std;

string map[5][5];
set<string> s;
int mX[4] = { 1,0,-1,0 };
int mY[4] = { 0,1,0,-1 };

void DFS(int x, int y, string str) {
	if (str.size() == 6) {		
		s.insert(str);
		return;
	}	
	for (int i = 0; i < 4; i++) {
		int nX = x + mX[i];
		int nY = y + mY[i];

		if (nX >= 0 && nX < 5 && nY >= 0 && nY < 5) {
			DFS(nX, nY, str+map[x][y]);
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			DFS(i, j, "");
		}
	}
	cout << s.size() << "\n";
}