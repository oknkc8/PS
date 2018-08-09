#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, adj2;
vector<int> ans;
int n, v[10005], dp[10005][2], check[10005];

void dfs(int x) {
	check[x] = 1;
	for (auto i : adj2[x]) {
		if (!check[i]) {
			check[i] = 1;
			adj[x].push_back(i);
			dfs(i);
		}
	}
}

int f(int x, int flag) {
	int &ret = dp[x][flag];
	if (ret!=-1) return ret;
	
	ret = 0;
	if (flag) {
		ret = v[x];
		for (auto i : adj[x]) ret += f(i, 0);
	}
	else {
		for (auto i : adj[x]) ret += max(f(i, 0), f(i, 1));
	}
	
	return ret;
}

void tracking(int x, int flag) {
	if (flag) {
		ans.push_back(x);
		for (auto i : adj[x]) tracking(i, 0);
	}
	else {
		for (auto i : adj[x]) {
			if (dp[i][0] >= dp[i][1]) tracking(i, 0);
			else tracking(i, 1);
		}
	}
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
	adj.resize(n + 1), adj2.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;	scanf("%d%d", &a, &b);
		adj2[a].push_back(b), adj2[b].push_back(a);
	}

	dfs(1);

	int x = f(1, 0), y = f(1, 1);
	if (x > y) {
		printf("%d\n", x);
		tracking(1, 0);
	}
	else {
		printf("%d\n", y);
		tracking(1, 1);
	}
	sort(ans.begin(), ans.end());
	for (auto i : ans) printf("%d ", i);

	return 0;
}