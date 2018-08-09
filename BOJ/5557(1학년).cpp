#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll v[105], dp[105][30];

ll f(int x, int s) {
	if (s < 0 || s>20) return 0;
	if (dp[x][s]) return dp[x][s];
	if (x == 0) {
		if (s==v[x]) return 1;
		else return 0;
	}

	ll &ret = dp[x][s];
	return ret = f(x - 1, s - v[x]) + f(x - 1, s + v[x]);
}

int main() {
	int n;	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &v[i]);

	printf("%lld", f(n - 2, v[n - 1]));

	return 0;
}