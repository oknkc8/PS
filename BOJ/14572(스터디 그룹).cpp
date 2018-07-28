#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct info {
	int m, d;
	vector<int> ai;
};

int n, k, d, p[30];

bool cmp(const info &p1, const info &p2) {
	if (p1.d < p2.d) return true;
	else if (p1.d > p2.d) return false;
	if (p1.m < p2.m) return true;
}

int group_count(int x) {
	int ret = 0;
	for (int i = 0; i < k; i++) if (p[i] == x) ret++;
	return ret;
}

int person_count() {
	int ret = 0;
	for (int i = 0; i < k; i++) if (p[i]) ret++;
	return ret;
}

int effort(info p1, info p2, int member) {
	if (p2.d - p1.d > d) return -1;
	int sc = person_count(), gc = group_count(member);

	return (sc - gc)*member;
}

int main() {
	scanf("%d%d%d", &n, &k, &d);
	vector<info> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &v[i].m, &v[i].d); v[i].ai.resize(v[i].m);
		for (int j = 0; j < v[i].m; j++) scanf("%d", &v[i].ai[j]);
	}
	sort(v.begin(), v.end(), cmp);

	queue<info> q;
	int sc = v[0].m, c = 1, ans = 0;
	q.push(v[0]);
	for (int i = 0; i < v[0].ai.size(); i++) p[v[0].ai[i] - 1]++;
	while (!q.empty()) {
		int e = effort(q.front(), q.back(), q.size());
		if (e >= 0) {
			ans = ans > e ? ans : e;
			if (c < n) {
				for (int i = 0; i < v[c].ai.size(); i++) p[v[c].ai[i] - 1]++;
				//sc += v[c].m;
				q.push(v[c++]);
			}
			else {
				info f = q.front();
				q.pop();
				for (int i = 0; i < f.ai.size(); i++) p[f.ai[i] - 1]--;
				//sc -= f.m;
			}
			continue;
		}
		info f = q.front();
		q.pop();
		for (int i = 0; i < f.ai.size(); i++) p[f.ai[i] - 1]--;
		//sc -= f.m;
	}

	printf("%d", ans);

	return 0;
}