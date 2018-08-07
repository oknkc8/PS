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

/*struct MCMF
{
	struct Edge
	{
		int from, to, cap, flow, cost, rev;
		Edge(int from, int to, int cap, int cost) : from(from), to(to), cap(cap), cost(cost), flow(0) {}
	};
	vector<vector<Edge>> G;
	vector<int> dist;
	vector<pair<int, int>> P;
	vector<bool> InQ;
	int N, src, sink;
	MCMF(int N, int src, int sink) : N(N), src(src), sink(sink) {
		G.resize(N);
		dist.resize(N);
		P.resize(N);
		InQ.resize(N);
	}
	void add_edge(int f, int t, int cap, int cost) {
		G[f].emplace_back(f, t, cap, cost);
		G[t].emplace_back(t, f, 0, -cost);
		G[f].back().rev = G[t].size() - 1;
		G[t].back().rev = G[f].size() - 1;
	}
	void add_edge_from_source(int t, int cap, int cost) {
		add_edge(src, t, cap, cost);
	}
	void add_edge_to_sink(int f, int cap, int cost) {
		add_edge(f, sink, cap, cost);
	}
	pair<int, int> flow() {
		pair<int, int> ret;
		queue<int> Q;
		for (;;) {
			int flow = 0x7fffffff;
			fill(P.begin(), P.end(), make_pair(-1, -1));
			fill(dist.begin(), dist.end(), 0x7fffffff);
			Q.push(src);
			dist[src] = 0;
			while (!Q.empty()) {
				int c = Q.front();
				Q.pop();
				InQ[c] = false;
				for (int i = 0; i < G[c].size(); i++) {
					auto &e = G[c][i];
					if (e.cap - e.flow > 0 && dist[e.to] > dist[e.from] + e.cost) {
						P[e.to] = { e.from,i };
						dist[e.to] = dist[e.from] + e.cost;
						if (!InQ[e.to]) {
							InQ[e.to] = true;
							Q.push(e.to);
						}
					}
				}
			}
			if (P[sink].first == -1) {
				break;
			}
			for (int now = sink; P[now].first != -1; now = P[now].first) {
				auto &e = G[P[now].first][P[now].second];
				flow = min(flow, e.cap - e.flow);
			}
			for (int now = sink; P[now].first != -1; now = P[now].first) {
				auto &e = G[P[now].first][P[now].second];
				e.flow += flow;
				G[e.to][e.rev].flow -= flow;
				ret.second += e.cost*flow;
			}
			ret.first += flow;
		}
		return ret;
	}
};

int main()
{
	int N, M;
	cin >> N >> M;
	MCMF mf(N + M + 2, N + M, N + M + 1);
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		mf.add_edge_from_source(i, a, 0);
	}
	for (int j = 0; j < M; j++) {
		int b;
		cin >> b;
		mf.add_edge_to_sink(N + j, b, 0);
	}
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {
			int c;
			cin >> c;
			mf.add_edge(i, N + j, 0x7fffffff, c);
		}
	}
	cout << mf.flow().second << '\n';
	return 0;
}*/