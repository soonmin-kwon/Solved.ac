#include<iostream>
#include<cstring>
using namespace std;

struct Trie {
	bool isTerminal;
	Trie* children[10]; // 1~10

	Trie() : isTerminal(false) {
		memset(children, 0, sizeof(children));
	}

	~Trie() {
		for (int i = 0; i < 10; ++i) {
			if (children[i])
				delete children[i];
		}
	}

	int ChangeToInt(char key) {
		return key - '0';
	}

	void Insert(const char* key) {
		if (*key == '\0') {
			isTerminal = true;
		}
		else {
			int index = ChangeToInt(*key);

			if (children[index] == 0) {
				children[index] = new Trie();
			}
			children[index]->Insert(key + 1);
		}
	}

	bool Find(const char* key) {
		if (*key == 0) {
			return true;
		}

		if (isTerminal) {
			return false;
		}

		int index = ChangeToInt(*key);		

		return children[index]->Find(key + 1);
	}
};
	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;	
	cin >> t;

	for (int j = 0; j < t; j++) {
		cin >> n;

		Trie* book = new Trie();
		string phoneNum[10001];		

		for (int i = 0; i < n; i++) {
			cin >> phoneNum[i];
			book->Insert(phoneNum[i].c_str());
		}

		bool check = true;

		for (int i = 0; i < n; i++) {
			if (book->Find(phoneNum[i].c_str()) == false) {
				check = false;
				break;
			}
		}

		delete book;

		if (check) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}