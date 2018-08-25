#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, dp[200005];
ll v[200005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &v[i]);
	
	int ans = 1;
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		if (v[i] <= v[i - 1] * 2) dp[i] = dp[i - 1] + 1;
		else dp[i] = 1;
		ans = max(ans, dp[i]);
	}

	printf("%d", ans);

	return 0;
}