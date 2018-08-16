#include<bits/stdc++.h>
using namespace std;

int v[50005];

int main() {
	int t, c = 0;	scanf("%d", &t);
	while (t--) {
		int n;	scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &v[i]);
		
		v[n] = 1000000001;
		int s = 0, m = 0, e = 0, flag = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!flag) {
				if (v[i - 1] < v[i]) m = i;
				else if (v[i - 1] > v[i]) flag = 1, e = i;
				else s = i, m = i, e = i, flag = 0;
			}
			else {
				if (v[i - 1] > v[i]) e = i;
				else {
					ans += (m - s)*(e - m);
					s = i - 1, m = i, e = i, flag = 0;
				}
			}
		}

		printf("#%d %d\n", ++c, ans);
	}

	return 0;
}