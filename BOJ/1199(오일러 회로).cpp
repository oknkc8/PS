#include<bits/stdc++.h>
using namespace std;

int n, adj[1005][1005], cnt, flag, deg[1005];
stack<int> ans;

void dfs(int x) {
	for (int i = 1; i <= n; i++) {
		while (adj[x][i]) {
			cnt--;
			adj[x][i]--, adj[i][x]--;
			dfs(i);
		}
	}
	printf("%d ", x);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &adj[i][j]);
			deg[i] += adj[i][j], deg[j] += adj[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		deg[i] /= 2;
		if (deg[i] % 2) {
			printf("-1");
			return 0;
		}
	}

	dfs(1);

	return 0;
}