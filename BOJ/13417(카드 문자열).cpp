#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		string str = "";
		char a;	cin >> a;
		str += a;
		for (int i = 1; i < n; i++) {
			cin >> a;
			if (str[0] >= a) {
				string str2 = "";
				str2 += a, str2 += str;
				str = str2;
			}
			else str += a;
		}
		cout << str << endl;
	}

	return 0;
}