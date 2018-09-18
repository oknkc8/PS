#include<bits/stdc++.h>
using namespace std;

int n, v[100005], k;
vector<pair<int, int>> a, t;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int x, y;	scanf("%d%d", &x, &y);
		a.push_back({ 2 * (i + 1) - 1, x });
		a.push_back({ 2 * (i + 1), -y });
	}

	int m = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		if (m < abs(a[i].second)) m = abs(a[i].second), t.push_back(a[i]);
	}

	vector<int> ans;
	sort(t.begin(), t.end());
	for (int i = n - 1; i >= abs(t[0].second); i--) ans.push_back(v[i]);
	sort(v, v + abs(t[0].second));
	int h = 0, e = abs(t[0].second) - 1;
	for (int i = 0; i < t.size() - 1; i++) {
		int x = abs(t[i].second) - abs(t[i + 1].second);
		if (t[i].second > 0) {
			for (int j = 0; j < x; j++) ans.push_back(v[e--]);
		}
		else {
			for (int j = 0; j < x; j++) ans.push_back(v[h++]);
		}
	}
	int x = t[t.size() - 1].second;
	if (x > 0) for (int i = 0; i < abs(x); i++) ans.push_back(v[e--]);
	else for (int i = 0; i < abs(x); i++) ans.push_back(v[h++]);

	for (int i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);

	return 0;
}