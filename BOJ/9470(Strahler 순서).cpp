#include<bits/stdc++.h>
using namespace std;


int k, m, p, dp[1005];
vector<vector<int>> adj(m + 1);

int f(int x) {
	if (!adj[x].size()) {
		return dp[x] = 1;
	}

	if (dp[x]) return dp[x];

	int t = 0, c = 0;
	for (auto togo : adj[x]) {
		int r = f(togo);
		if (r > t) {
			t = r, c = 1;
		}
		else if (r == t) c++;
	}
	if (c == 1) return dp[x] = t;
	else return dp[x] = t + 1;
}

int main() {
	int T;	scanf("%d", &T);
	while (T--) {
		memset(dp, 0, sizeof(dp));
		scanf("%d %d %d", &k, &m, &p);
		adj.clear(), adj.resize(m + 1);
		for (int i = 0; i < p; i++) {
			int a, b;	scanf("%d %d", &a, &b);
			adj[b].push_back(a);
		}

		printf("%d %d\n", k, f(m));
	}

	return 0;
}