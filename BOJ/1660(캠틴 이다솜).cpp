#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int dp[300005];

int main() {
	int s = 0;
	v.push_back(0);
	for (int i = 1;; i++) {
		s += i;
		if (s + v[i - 1] > 300000) break;
		v.push_back(s + v[i - 1]);
	}

	int n;	scanf("%d", &n);
	for (int i = 1; i < v.size(); i++) {
		for (int j = v[i]; j <= n; j++) {
			if (j==v[i] || dp[j - v[i]] && (dp[j - v[i]] + 1 < dp[j] || !dp[j]))
				dp[j] = dp[j - v[i]] + 1;
		}
	}

	printf("%d", dp[n]);

	return 0;
}