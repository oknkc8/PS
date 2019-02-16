#include<bits/stdc++.h>
using namespace std;

int n, v[100005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	sort(v, v + n);

	int t = v[n - 1] - v[0];
	vector<int> p;
	for (int i = 1; i*i <= t; i++) {
		if (t%i == 0) {
			p.push_back(i);
			if (i*i != t) p.push_back(t / i);
		}
	}
	sort(p.begin(), p.end());

	int ans = INT_MAX;
	for (int i = 0; i < p.size(); i++) {
		int a = p[i], flag = 0, s = 0;
		for (int j = 1; j < n; j++) {
			if ((v[j] - v[j - 1]) % a) {
				flag = 1;
				break;
			}
			s += (v[j] - v[j - 1]) / a - 1;
		}
		if (!flag) ans = min(ans, s);
	}

	printf("%d", ans);

	return 0;
}