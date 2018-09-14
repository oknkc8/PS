#include<bits/stdc++.h>
using namespace std;

struct info {
	int x, y, v, n;
	double t;

	bool operator()(info p, info q) {
		if (p.t == q.t) return p.n < q.n;
		if (p.t < q.t) return true;
		else return false;
	}
};

info a[100005];

int main() {
	int n;	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
		a[i].n = i + 1;
		a[i].t = sqrt(a[i].x*a[i].x + a[i].y*a[i].y) / (double)a[i].v;
	}
	sort(a, a + n, info());
	for (int i = 0; i < n; i++) printf("%d\n", a[i].n);

	return 0;
}