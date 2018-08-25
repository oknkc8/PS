#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;	cin >> n >> k;
	string str;	cin >> str;

	int m = 0;
	for (int i = 1; i < n; i++) {
		int flag = 0;
		for (int j = n-i; j < n; j++) {
			if (str[j] != str[j - (n - i)]) {
				flag = 1;	break;
			}
		}
		if (!flag) m = max(m, i);
	}
	
	cout << str;
	string str2 = str.substr(m, n - m);
	for (int i = 0; i < k-1; i++) cout << str2;

	return 0;
}