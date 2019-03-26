#include<bits/stdc++.h>
using namespace std;

#define cal(x) (x&(-x))

int n, v[100005], tree[100005];

void update(int x, int a) {
	while (x <= n) {
		tree[x] += a;
		x += cal(x);
	}
}

int sum(int x) {
	int ret = 0;
	while (x > 0) {
		ret += tree[x];
		x -= cal(x);
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		v[a] = i;
		update(i, 1);
	}

	int h = 1, t = n, idx;
	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			idx = v[h++];
			printf("%d\n", sum(idx) - 1);
		}
		else {
			idx = v[t--];
			printf("%d\n", n - i + 1 - sum(idx));
		}
		update(idx, -1);
	}

	return 0;
}