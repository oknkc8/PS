#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;	cin >> str;
	int c1 = 0, c2 = 0, f1 = 0, f2 = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '0') {
			if (f2 || i == 0) {
				c1++, f1 = 1, f2 = 0;
			}
		}
		else {
			if (f1 || i == 0) {
				c2++, f2 = 1, f1 = 0;
			}
		}
	}

	cout << min(c1, c2);

	return 0;
}