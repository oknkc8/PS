#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> dp[9];

ll get_one(int x) {
	ll ret = 0;
	while (x--) {
		ret *= 10;
		ret++;
	}
	return ret;
}

int main() {
	int k;	scanf("%d", &k);
	dp[1].push_back(k);
	for (int i = 2; i <= 8; i++) {
		for (int j = 1; j < i; j++) {
			for (ll x : dp[j]) {
				for (ll y : dp[i - j]) {
					dp[i].push_back(x + y);
					dp[i].push_back(x - y);
					dp[i].push_back(x * y);
					if(y) dp[i].push_back(x / y);
				}
			}
		}
		dp[i].push_back(get_one(i)*k);
		sort(dp[i].begin(), dp[i].end());
		dp[i].erase(unique(dp[i].begin(), dp[i].end()), dp[i].end());
	}

	int t;	scanf("%d", &t);
	while (t--) {
		int n, flag = 0;	scanf("%d", &n);
		for (int i = 1; i <= 8; i++) {
			for (auto x : dp[i]) {
				if (x == (ll)n) {
					flag = 1;	printf("%d\n", i);
					break;
				}
			}
			if (flag) break;
		}
		if (!flag) printf("NO\n");
	}

	return 0;
}