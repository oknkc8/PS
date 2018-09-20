#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m, c1, c2;	cin >> n >> m >> c1 >> c2;
	vector<int> p(n), q(m);
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < m; i++) cin >> q[i];
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());

	map<int, int> ans;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(q.begin(), q.end(), p[i]) - q.begin();
		
		if (!idx) ans[abs(c1 - c2) + abs(p[i] - q[idx])]++;
		else if (idx == m) ans[abs(c1 - c2) + abs(p[i] - q[m - 1])]++;
		else {
			ans[abs(c1 - c2) + abs(p[i] - q[idx - 1])]++;
			ans[abs(c1 - c2) + abs(p[i] - q[idx])]++;
		}
	}

	cout << ans.begin()->first << " " << ans.begin()->second;

	return 0;
}