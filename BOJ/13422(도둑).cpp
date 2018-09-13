#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int v[200005];

int main() {
	int t;	scanf("%d", &t);
	while (t--) {
		memset(v, 0, sizeof(v));
		int n, m, k;	scanf("%d%d%d", &n, &m, &k);
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
			if (i < m) v[n + i] = v[i], sum += (ll)v[i];
		}
		int ans = (sum < (ll)k);
		if (n != m) {
			for (int i = 1; i < n; i++) {
				sum = sum - (ll)v[i - 1] + (ll)v[i + m - 1];
				ans += (sum < (ll)k);
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}