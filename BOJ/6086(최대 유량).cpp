#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(52);
bool visit[100];
int c[100][100], f[100][100], sink = 25;

int dfs(int x, int flow) {
	if (x == sink) return flow;

	visit[x] = true;
	for (auto i : adj[x]) {
		if (c[x][i] - f[x][i] > 0 && !visit[i]) {
			visit[i] = true;
			int ret = dfs(i, min(c[x][i] - f[x][i], flow));
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
	int n;	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b;	int x;	cin >> a >> b >> x;
		if (a > 'Z') a -= 6;
		if (b > 'Z') b -= 6;
		adj[a - 'A'].push_back(b - 'A');
		adj[b - 'A'].push_back(a - 'A');
		c[a - 'A'][b - 'A'] += x;
		c[b - 'A'][a - 'A'] += x;
	}

	int ans = 0;
	while (1) {
		fill(visit, visit + 100, false);
		int flow = dfs(0, 1e9);
		if (!flow) break;
		ans += flow;
	}
	printf("%d", ans);

	return 0;
}