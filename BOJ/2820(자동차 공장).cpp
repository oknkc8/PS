#include<bits/stdc++.h>
using namespace std;
#define cal(x) (x&(-x))
typedef long long ll;

int n, cnt;
ll tree[2000005], lazy[2000005], p[500005];
vector<vector<int>> adj;
pair<int, int> v[500005];

void update(int node, int s, int e, int index, int val) {
	if (index < s || e < index) return;
	if (s == e) {
		tree[node] = val;
		return;
	}

	update(node * 2, s, (s + e) / 2, index, val);
	update(node * 2 + 1, (s + e) / 2 + 1, e, index, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update_lazy(int node, int s, int e) {
	if (lazy[node] != 0) {
		tree[node] += (e - s + 1)*lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];		lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	return;
}

void update_range(int node, int s, int e, int l, int r, long long val) {
	update_lazy(node, s, e);

	if (l > e || r < s) return;
	if (l <= s & e <= r) {
		tree[node] += (e - s + 1)*val;
		if (s != e) {
			lazy[node * 2] += val;		lazy[node * 2 + 1] += val;
		}
		return;
	}

	update_range(node * 2, s, (s + e) / 2, l, r, val);
	update_range(node * 2 + 1, (s + e) / 2 + 1, e, l, r, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum(int node, int s, int e, int l, int r) {
	update_lazy(node, s, e);
	if (l > e || r < s) return 0;
	if (l <= s && e <= r) return tree[node];

	return sum(node * 2, s, (s + e) / 2, l, r) + sum(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int dfs(int x) {
	v[x].first = ++cnt;

	int ret = 0;
	for (auto togo : adj[x]) {
		ret = dfs(togo);
	}
	
	if (!ret) ret = cnt;
	return v[x].second = cnt;
}


int main() {
	int m;	scanf("%d%d", &n, &m);
	adj.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		int a, b;
		if (i == 1) scanf("%d", &p[i]);
		else {
			scanf("%d%d", &a, &b);
			adj[b].push_back(i);
			p[i] = a;
		}
	}

	dfs(1);
	for (int i = 1; i <= n; i++) update(1, 1, n, v[i].first, p[i]);

	while (m--) {
		char s;	scanf(" %c", &s);
		if (s == 'p') {
			int a, x;	scanf("%d%d", &a, &x);
			if (v[a].first == v[a].second) continue;
			update_range(1, 1, n, v[a].first + 1, v[a].second, x);
		}
		else {
			int a;	scanf("%d", &a);
			printf("%lld\n", sum(1, 1, n, v[a].first, v[a].first));
		}
	}

	return 0;
}