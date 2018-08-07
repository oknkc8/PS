#include<bits/stdc++.h>
using namespace std;
#define INF 10000000

int n, m, c[205][205], f[205][205], dist[205];
vector<vector<pair<int, int>>> adj;
vector<pair<int, int>> p;
bool inq[205];

int main() {
	scanf("%d%d", &n, &m);
	//source = 0, sink = n+m+1
	adj.resize(n + m + 2);
	for (int i = 1; i <= n; i++) {
		int a;	scanf("%d", &a);
		adj[0].push_back({ i,0 }), adj[i].push_back({ 0,0 });
		c[0][i] = a;
	}
	for (int i = n + 1; i <= n + m; i++) {
		int a;	scanf("%d", &a);
		adj[i].push_back({ n + m + 1,0 }), adj[n + m + 1].push_back({ i,0 });
		c[i][n + m + 1] = a;
	}
	for (int i = n + 1; i <= n + m; i++) {
		for (int j = 1; j <= n; j++) {
			int a;	scanf("%d", &a);
			adj[j].push_back({ i,a }), adj[i].push_back({ j,-a });
			c[j][i] = INF;
		}
	}

	int ans = 0;
	queue<int> Q;
	p.resize(n + m + 2);
	while (1) {
		int flow = INF;
		fill(dist, dist + 205, INF);
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
					p[togo.first] = {now,i};
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
			//auto i = adj[p[now].first][p[now].second];
			flow = min(flow, c[p[now].first][now] - f[p[now].first][now]);
		}
		for (int now = n + m + 1; p[now].first != -1; now = p[now].first) {
			auto i = adj[p[now].first][p[now].second];
			f[now][p[now].first] -= flow;
			f[p[now].first][now] += flow;
			ans += i.second*flow;
		}
	}

	printf("%d", ans);

	return 0;
}


