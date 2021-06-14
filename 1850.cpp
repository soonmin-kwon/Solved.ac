#include<iostream>
#include<cstring>
using namespace std;

long long int Greatest(long long int a, long long int b) {
	long long int remainder;
	while (a) {
		remainder = b % a;
		b = a;
		a = remainder;
	}
	return b;
}

int main() {
	long long int a, b;
	long long int temp1;
	string answer ="";
	cin >> a >> b;

	if (a > b) {
		long long int temp = a;
		a = b;
		b = temp;
	}
	temp1 = Greatest(a, b);
	for (long long int i = 0; i < temp1; i++) {
		answer += '1';
	}	
	cout << answer << "\n";
}