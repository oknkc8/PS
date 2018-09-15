#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int v[1005][2];

int main() {
	int t;	scanf("%d", &t);
	while (t--) {
		ll n;	scanf("%lld", &n);
		memset(v, 0, sizeof(v));
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				int a;	scanf("%d", &a);
				v[i][a]++, v[i + 1 + j][a]++;
			}
		}
		
		ll ans = n * (n - 1)*(n - 2) / 6, sum = 0;
		for (int i = 0; i < n; i++) sum += v[i][0] * v[i][1];
		printf("%lld\n", ans - sum / 2);
	}

	return 0;
}