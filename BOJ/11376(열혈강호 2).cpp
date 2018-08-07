#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n, m, c[2005][2005], f[2005][2005];
bool visit[2005];

int mf(int x, int flow) {
	if (x == n + m + 1) return flow;
	//if (visit[x]) return 0;

	visit[x] = true;
	for (auto i : adj[x]) {
		if (c[x][i] - f[x][i] > 0 && !visit[i]) {
			//visit[i] = true;
			int ret = mf(i, min(c[x][i] - f[x][i], flow));
			if (ret > 0) {
				f[x][i] += ret;
				f[i][x] -= ret;
				return ret;
			}
		}
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &m);
	adj.resize(n + m + 2);
	for (int i = 0; i < n; i++) {
		adj[0].push_back(i + 1), c[0][i + 1] = 2;
		adj[i + 1].push_back(0);
		int a;	scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			int x;	scanf("%d", &x);
			adj[i + 1].push_back(x + n);
			adj[x + n].push_back(i + 1);
			c[i + 1][x + n] = 1;
		}
	}
	for (int i = 1; i <= m; i++) adj[n + i].push_back(n + m + 1), c[n + i][n + m + 1] = 1, adj[n + m + 1].push_back(n + i);

	int ans = 0;
	for (;;) {
		fill(visit, visit + 2005, false);
		int flow = mf(0, 1e9);
		if (!flow) break;
		ans += flow;
	}
	printf("%d", ans);

	return 0;
}