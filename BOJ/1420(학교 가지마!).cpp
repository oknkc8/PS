#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

struct MaximnumFlow {
	struct Edge {
		int from, to, cap, flow, rev;
		Edge(int from, int to, int cap) : from(from), to(to), cap(cap), flow(0) {}
	};
	vector<vector<Edge>> adj;
	vector<pair<int, int>> p;
	vector<bool> visit;
	int N, source, sink;
	MaximnumFlow(int N, int source, int sink) :N(N), source(source), sink(sink) {
		adj.resize(N);
		p.resize(N);
		visit.resize(N);
	}
	void add_edge(int from, int to, int cap) {
		adj[from].emplace_back(from, to, cap);
		adj[to].emplace_back(to, from, 0);
		adj[from].back().rev = adj[to].size() - 1;
		adj[to].back().rev = adj[from].size() - 1;
	}
	void add_edge_from_source(int to, int cap) {
		add_edge(source, to, cap);
	}
	void add_edge_to_sink(int from, int cap) {
		add_edge(from, sink, cap);
	}
	int Flow() {
		int ret = 0;
		queue<int> q;
		while (1) {
			int flow = INF;
			fill(p.begin(), p.end(), make_pair(-1, -1));
			fill(visit.begin(), visit.end(), false);
			q.push(source);
			visit[source] = true;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				for (int i = 0; i < adj[now].size(); i++) {
					auto &e = adj[now][i];
					if (e.cap - e.flow > 0 && !visit[e.to]) {
						visit[e.to] = true;
						p[e.to] = { e.from,i };
						q.push(e.to);
					}
				}
			}

			if (p[sink].first == -1) break;
			for (int now = sink; p[now].first != -1; now = p[now].first) {
				auto &e = adj[p[now].first][p[now].second];
				flow = min(flow, e.cap - e.flow);
			}
			for (int now = sink; p[now].first != -1; now = p[now].first) {
				auto &e = adj[p[now].first][p[now].second];
				e.flow += flow;
				adj[e.to][e.rev].flow -= flow;
			}
			ret += flow;
		}
		
		return ret;
	}
};

int n, m, sx, sy, ex, ey;
vector<string> mp;

int node(int x, int y, int flag) {
	return 2 * (x*m + y) + flag;
}

int main() {
	scanf("%d%d", &n, &m);
	MaximnumFlow mf(2 * n*m + 2, 2 * n*m, 2 * n*m + 1);
	mp.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> mp[i];
		for (int j = 0; j < m; j++) {
			if (mp[i][j] == 'K') {
				sx = i, sy = j;
				mf.add_edge_from_source(node(i, j, 1), INF);
			}
			else if (mp[i][j] == 'H') {
				ex = i, ey = j;
				mf.add_edge_to_sink(node(i, j, 0), INF);
			}
			if (mp[i][j] != '#') {
				mf.add_edge(node(i, j, 0), node(i, j, 1), 1);
				if (i && mp[i - 1][j] != '#') {
					mf.add_edge(node(i - 1, j, 1), node(i, j, 0), INF);
					mf.add_edge(node(i, j, 1), node(i - 1, j, 0), INF);
				}
				if (j&&mp[i][j - 1] != '#') {
					mf.add_edge(node(i, j - 1, 1), node(i, j, 0), INF);
					mf.add_edge(node(i, j, 1), node(i, j - 1, 0), INF);
				}
			}
		}
	}
	if (abs(sx - ex) + abs(sy - ey) == 1) printf("-1");
	else printf("%d", mf.Flow());

	return 0;
}