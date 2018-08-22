#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[100005][3], v[100005][3];

int main() {
	int c = 0;
	while (1) {
		int n=0;	scanf("%d", &n);
		if (!n) break;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) scanf("%lld%lld%lld", &v[i][0], &v[i][1], &v[i][2]);
		
		dp[0][0] = 10000000;
		for (int i = 0; i < n; i++) {
			if (!i) {
				dp[i][1] = v[i][1];
				dp[i][2] = dp[i][1] + v[i][2];
			}
			else {
				dp[i][0] = v[i][0] + min(dp[i - 1][0], dp[i - 1][1]);
				dp[i][1] = v[i][1] + min(dp[i][0], min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])));
				dp[i][2] = v[i][2] + min(dp[i][1], min(dp[i - 1][1], dp[i - 1][2]));
			}
		}

		printf("%d. %lld\n", ++c, dp[n - 1][1]);
	}

	return 0;
}