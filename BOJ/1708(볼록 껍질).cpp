#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
typedef long long ll;

struct point {
	ll x, y, dist;
	long double dx, dy, s;
};

bool cmp(point a, point b) {
	if (a.s == b.s) {
		if (a.dist < b.dist) return true;
	}
	else if (a.s < b.s) return true;
	return false;
}

bool ccw(point a, point b, point c) {
	return ((b.x - a.x)*(c.y - a.y)-(b.y - a.y)*(c.x - a.x)) > 0;
}

vector<point> p;

int main() {
	int n,idx;	scanf("%d", &n);
	point mp;
	p.resize(n);
	mp.x = INF, mp.y = INF;
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &p[i].x, &p[i].y);
		if (mp.x > p[i].x || (mp.x == p[i].x && mp.y > p[i].y)) mp = p[i], idx = i;
	}
	for (int i = 0; i < n; i++) {
		p[i].dx = p[i].x - mp.x;
		p[i].dy = p[i].y - mp.y;
		p[i].dist = p[i].dx*p[i].dx + p[i].dy*p[i].dy;
		if (!p[i].dx) p[i].s = INF;
		else p[i].s = p[i].dy / p[i].dx;
	}
	p.erase(p.begin() + idx);
	sort(p.begin(), p.end(), cmp);
	p.push_back(mp);

	stack<point> st;
	st.push(p[n - 1]);
	st.push(p[0]);
	for (int i = 1; i < n; i++) {
		point top2 = st.top();
		st.pop();
		point top1 = st.top();
		st.pop();
		st.push(top1);
		if (!ccw(top1, top2, p[i])) st.push(p[i]);
		else {
			st.push(top2);
			st.push(p[i]);
		}
	}

	printf("%d", st.size()-1);

	return 0;
}