#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct info {
	int st, en, val;
};

int n, m, d[105], s, t;
ll val[105];
int check[105];
vector<info> e;
vector<vector<pair<int, int>>> adj;

bool dfs(int x) {
	if (x == t) {
		return true;
	}
	check[x] = 1;
	for (auto i : adj[x]) {
		if (!check[i.first]) {
			bool ret = dfs(i.first);
			if (ret) return ret;
		}
	}
	return false;
}

int main() {
	cin >> n >> s >> t >> m;
	adj.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;	cin >> a >> b >> c;
		e.push_back({ a,b,c });
		adj[a].push_back({ b, c });
	}
	for (int i = 0; i < n; i++) cin >> d[i];

	fill(val, val + n, -(1e9));

	val[s] = d[s];

	int c = 0, flag = 1, gee[512] = { 0 };
	while (flag&&c != n) {
		flag = 0;

		for (int j = 0; j < m; j++) {
			if (val[e[j].en] < val[e[j].st] - e[j].val + d[e[j].en] && val[e[j].st] != -(1e9)) {
				val[e[j].en] = val[e[j].st] - e[j].val + d[e[j].en];
				flag = 1;
				if (c == n - 1) gee[e[j].st] = 1;
			}
		}
		c++;
	}

	flag = 0;
	for (int i = 0; i < n; i++) {
		if (gee[i]) {
			memset(check, 0, sizeof(check));
			if (dfs(i)) {
				flag = 1;	break;
			}
		}
	}


	if (val[t] == -(1e9)) {
		printf("gg\n");
	}
	else if (flag) {
		printf("Gee\n");
	}
	else {
		cout << val[t];
	}

	return 0;
}