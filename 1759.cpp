#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

vector<char> code;
vector<string> answers;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int l, c;
	int checkConso, checkVowel;
	char alpha;
	cin >> l >> c;

	vector<bool> check(c, false);
	for (int i = 0; i < l; i++) {
		check[i] = true;
	}

	for (int i = 0; i < c; i++) {
		cin >> alpha;
		code.push_back(alpha);
	}

	sort(code.begin(), code.end());

	do {
		string temp = "";
		checkConso = 0;
		checkVowel = 0;

		for (int i = 0; i < c; i++) {			
			if (check[i]) {
				if (code[i] - 'a' == 0 || code[i] - 'a' == 4 || code[i] - 'a' == 8 || code[i] - 'a' == 14 || code[i] - 'a' == 20) {
					checkConso++;
					temp += code[i];
				}
				else {
					checkVowel++;
					temp += code[i];
				}
			}
		}

		if (checkConso >= 1 && checkVowel >= 2) {
			answers.push_back(temp);
		}

	} while (prev_permutation(check.begin(), check.end()));

	int len = answers.size();

	for (int i = 0; i < len; i++) {
		cout << answers[i] << "\n";
	}
}