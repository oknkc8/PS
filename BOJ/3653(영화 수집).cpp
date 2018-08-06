#include<bits/stdc++.h>
using namespace std;
#define cal(x) ((x)&(-x))
#define INF 200000

int n, m, tree[1000000], c[100005], p;

void update(int x, int val) {
	while (x <= INF + n) {
		tree[x]+=val;
		x += cal(x);
	}
}

int get(int x) {
	int ret = 0;
	while (x > 0) {
		ret += tree[x];
		x -= cal(x);
	}
	return ret ? ret - 1 : ret;
}

int main() {
	int t;	scanf("%d", &t);
	while (t--) {
		memset(tree, 0, sizeof(tree));
		memset(c, 0, sizeof(c));
		p = 0;

		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			c[i] = i;
			update(i + INF, 1);
		}

		for (int i = 0; i < m; i++) {
			int a;	scanf("%d", &a);
			printf("%d ", get(c[a] + INF));
			update(c[a] + INF, -1);
			update((--p) + INF, 1);
			c[a] = p;
		}
	}

	return 0;
}