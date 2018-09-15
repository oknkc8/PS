#include<bits/stdc++.h>
using namespace std;
#define cal(x) (x&(-x))

int n, v[100005], a[100005], tree[400000];

int get() {
	int ret = 1;
	while (ret < n) ret *= 2;
	return ret;
}

void update(int x, int val) {
	tree[x] += val;
	int node = x / 2;
	while (node) {
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
		node /= 2;
	}
}

int main() {
	scanf("%d", &n);
	int idx = get();

	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(v, v + n);

	for (int i = 0; i < n; i++) update(i + idx, 1);

	vector<int> ans;
	for (int i = n - 1; i >= 0; i--) {
		int x = a[i] + 1;
		int node = 1;
		while (node < idx) {
			if (tree[node*2] >= x) node *= 2;
			else {
				x -= tree[node*2];
				node = node * 2 + 1;
			}
		}
		ans.push_back(node - idx);
		update(node, -1);
	}

	for (int i = n - 1; i >= 0; i--) printf("%d\n", v[ans[i]]);

	return 0;
}