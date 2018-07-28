#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

struct info {
	int x1, x2, y1, y2;
};

int n;
vector<info> v;
vector<int> x, y;

bool check(int x1, int y1, int x2, int y2) {
	for (int i = 0; i < n; i++) {
		if (v[i].x1 <= x1 && x2 <= v[i].x2 && v[i].y1 <= y1 && y2 <= v[i].y2) return true;
	}
	return false;
}

int main() {
	scanf("%d", &n);	v.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &v[i].x1, &v[i].y1, &v[i].x2, &v[i].y2);
		x.push_back(v[i].x1), x.push_back(v[i].x2);
		y.push_back(v[i].y1), y.push_back(v[i].y2);
	}

	sort(x.begin(), x.end()), x.erase(unique(x.begin(), x.end()), x.end());
	sort(y.begin(), y.end()), y.erase(unique(y.begin(), y.end()), y.end());

	ll ans = 0;
	for (int i = 0; i < x.size() - 1; i++) {
		for (int j = 0; j < y.size() - 1; j++) {
			if (check(x[i], y[j], x[i + 1], y[j + 1])) ans += (x[i + 1] - x[i])*(y[j + 1] - y[j]) * 1LL;
		}
	}

	printf("%lld", ans);

	return 0;
}