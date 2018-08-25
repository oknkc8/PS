#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
priority_queue<int> x, y;

int main() {
	int n;	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;	scanf("%d%d", &a, &b);
		v.push_back({ a,b });
		x.push(a), y.push(-b);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a = x.top(), b = y.top(), f1 = 0, f2 = 0;
		if (a == v[i].first) f1 = 1, x.pop(), a = x.top();
		if (b == (-v[i].second)) f2 = 1, y.pop(), b = y.top();
		b *= -1;

		if (b > a) ans = max(ans, b - a);
		if (f1) x.push(v[i].first);
		if (f2) y.push(-v[i].second);
	}

	printf("%d", ans);

	return 0;
}