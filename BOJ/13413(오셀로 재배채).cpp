#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;	scanf("%d", &t);
	while (t--) {
		int n, c = 0;;	scanf("%d", &n);
		string s1, s2, str = "";	cin >> s1 >> s2;
		for (int i = 0; i < n; i++) {
			if (s1[i] != s2[i]) {
				str += s1[i];
				c += s1[i] == 'W';
			}
		}

		int e = str.size();
		printf("%d\n", max(e - c, c));
	}

	return 0;
}