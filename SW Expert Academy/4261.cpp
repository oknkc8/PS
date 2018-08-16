#include<bits/stdc++.h>
using namespace std;

int f(char a) {
	int e = a - 97;
	if (a == 'z') return 9;
	return e / 3 + 2;
}

int main() {
	int t, c = 0;	cin >> t;
	while (t--) {
		string str;
		int n, a[1005], ans = 0;
		cin >> str >> n;
		for (int i = 0; i < str.size(); i++) a[i] = str[i] - '0';

		for (int i = 0; i < n; i++) {
			string s;	cin >> s;
			if (s.size() != str.size()) continue;
			int cnt = 0;
			for (int j = 0; j < s.size(); j++) {
				if (a[j] == f(s[j])) cnt++;
				else break;
			}
			if (cnt == str.size()) ans++;
		}
		printf("#%d %d\n", ++c, ans);
	}

	return 0;
}