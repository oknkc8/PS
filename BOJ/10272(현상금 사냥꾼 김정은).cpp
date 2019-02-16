#include<bits/stdc++.h>
using namespace std;

int n;
pair<int, int> xy[550];
double dp[550][550];

double dist(int a, int b) {
	return sqrt((xy[a].first - xy[b].first)*(xy[a].first - xy[b].first)
		+ (xy[a].second - xy[b].second)*(xy[a].second - xy[b].second));
}

double f(int l, int r) {
	if (r == n - 1) return dist(l, r);
	if (dp[l][r]) return dp[l][r];
	return dp[l][r] = min(f(l, r + 1) + dist(r, r + 1), f(r, r + 1) + dist(l, r + 1));
}

int main() {
	int T;	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> xy[i].first >> xy[i].second;
		memset(dp, 0, sizeof(dp));

		printf("%lf\n", f(0, 0));
	}

	return 0;
}