#include<bits/stdc++.h>
using namespace std;

int n, c[10005];
int dp[2][10005], visit[10005];
vector<vector<int>> t_adj, adj;

void init_dfs(int now) {
	visit[now] = 1;

	for (auto togo : t_adj[now]) {
		if (!visit[togo]) {
			adj[now].push_back(togo);
			init_dfs(togo);
		}
	}
}

int dfs(int now, int flag, int pre_flag) {
	if (dp[flag][now] != -1) return dp[flag][now];

	// not selected
	int &ret = dp[flag][now];
	int s = 0;
	
	ret = 0;
	if (!flag) {
		for (auto togo : adj[now]) {
			s += max(dfs(togo, 0, flag), dfs(togo, 1, flag));
		}
		return ret = s;
	}
	else {
		for (auto togo : adj[now]) {
			s += dfs(togo, 0, flag);
		}
		return ret = s + c[now];
	}
}

int main() {
	scanf("%d", &n);	adj.resize(n + 1), t_adj.resize(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b;	scanf("%d%d", &a, &b);
		t_adj[a].push_back(b);
		t_adj[b].push_back(a);
	}

	init_dfs(1);

	for (int i = 1; i <= n; i++) dp[0][i] = dp[1][i] = -1;

	printf("%d", max(dfs(1, 0, 0), dfs(1, 1, 0)));

	return 0;
}