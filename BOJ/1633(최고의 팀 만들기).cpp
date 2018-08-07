#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000

vector<vector<pair<int, int>>> adj;
vector<pair<int, int>> p;
vector<int> dist, w, b;
bool inq[1005];
int n, m = 2, c[1005][1005], f[1005][1005];

int main() {
	int x, y;
	while (~scanf("%d%d", &x, &y)) {
		w.push_back(x), b.push_back(y);
	}
	n = w.size();
	adj.resize(n + m + 2);
	for (int i = 1; i <= n; i++) {
		adj[0].push_back({ i,0 }), adj[i].push_back({ 0,0 });
		c[0][i] = 1;
		adj[i].push_back({ n + 1, -w[i - 1] }), adj[i].push_back({ n + 2, -b[i - 1] });
		adj[n + 1].push_back({ i, w[i - 1] }), adj[n + 2].push_back({ i,b[i - 1] });
		c[i][n + 1] = 1, c[i][n + 2] = 1;
	}
	adj[n + 1].push_back({ n + m + 1,0 }), adj[n + 2].push_back({ n + m + 1,0 });
	c[n + 1][n + m + 1] = c[n + 2][n + m + 1] = 15;

	int ans = 0;
	queue<int> Q;
	dist.resize(n + m + 2);
	p.resize(n + m + 2);
	while (1) {
		int flow = INF;
		fill(dist.begin(), dist.end(), INF);
		fill(p.begin(), p.end(), make_pair(-1, -1));
		Q.push(0);
		dist[0] = 0;

		while (!Q.empty()) {
			int now = Q.front();
			Q.pop();
			inq[now] = false;
			for (int i = 0; i < adj[now].size(); i++) {
				auto togo = adj[now][i];
				if (c[now][togo.first] - f[now][togo.first] > 0 && dist[togo.first] > dist[now] + togo.second) {
					p[togo.first] = { now,i };
					dist[togo.first] = dist[now] + togo.second;
					if (!inq[togo.first]) {
						inq[togo.first] = true;
						Q.push(togo.first);
					}
				}
			}
		}

		if (p[n + m + 1].first == -1) break;

		for (int now = n + m + 1; p[now].first != -1; now = p[now].first) {
			flow = min(flow, c[p[now].first][now] - f[p[now].first][now]);
		}
		for (int now = n + m + 1; p[now].first != -1; now = p[now].first) {
			auto i = adj[p[now].first][p[now].second];
			f[p[now].first][now] += flow;
			f[now][p[now].first] -= flow;
			ans += (-1)*i.second*flow;
		}
	}
	printf("%d\n", ans);

	return 0;
}