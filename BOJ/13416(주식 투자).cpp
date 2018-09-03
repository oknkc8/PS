#include<bits/stdc++.h>
using namespace std;

int v[1005][3];

int main() {
	int t;	scanf("%d", &t);
	while (t--) {
		int n, ans = 0;	scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) scanf("%d", &v[i][j]);
			ans += max(0, max(v[i][0], max(v[i][1], v[i][2])));
		}
		printf("%d\n", ans);
	}

	return 0;
}