#include<iostream>
#include<string>
using namespace std;

int main() {

	string inp;
	string temp;
	char pm;
	int sol = 111111;
	cin >> inp;
	bool check = false;
	bool init = true;	
	for (int i = 0; i < inp.size(); i++) {

		if (inp[i] == '-' ) {
			if (init) {
				init = false;
				sol = stoi(temp);
				
				pm = inp[i];
			}
			else {
				if (pm == '-') {
					sol -= stoi(temp);									
				}
				if (pm == '+') {
					sol += stoi(temp);
					pm = '-';
				}
			}		
			temp = "";
		}

		if (inp[i] == '+') {
			if (init) {
				init = false;
				sol = stoi(temp);
				pm = '+';
			}
			else {
				if (pm == '-') {
					sol -= stoi(temp);		
				}
				if (pm=='+') {
					sol += stoi(temp);
					pm = '+';
				}
			}
			temp = "";
		}
		if (inp[i] != '+' && inp[i] != '-') {
			temp += inp[i];
		}		
	}
	if (init) {
		cout << stoi(temp) << endl;
		return 0 ;
	}
	if (pm == '+') {
		cout << sol + stoi(temp) << endl;
	}
	if (pm == '-') {
		cout << sol - stoi(temp) << endl;
	}
	
}