#include<bits/stdc++.h>
using namespace std;

int v[6] = { 1,5,10,50,100,500 }, dp[1005];

int main() {
	int n;	cin >> n;
	n = 1000 - n;

	for (int i = 0; i < 6; i++) {
		dp[v[i]] = 1;
		for (int j = v[i] + 1; j <= n; j++) {
			if (dp[j - v[i]]) {
				if (!dp[j]) dp[j] = dp[j - v[i]] + 1;
				else dp[j] = min(dp[j], dp[j - v[i]] + 1);
			}
		}
	}

	cout << dp[n];

	return 0;
}