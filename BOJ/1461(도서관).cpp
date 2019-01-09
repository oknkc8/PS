#include<bits/stdc++.h>
using namespace std;

int n, m, v[10005], ans;
vector<int> a;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	sort(v, v + n);

	for (int i = 0; i < n &&v[i] < 0; i += m) a.push_back(abs(v[i]));
	for (int i = n - 1; i >= 0 && v[i] > 0; i -= m) a.push_back(abs(v[i]));

	sort(a.begin(), a.end());

	for (auto i : a) ans += (i * 2);
	ans -= a[a.size() - 1];

	cout << ans;

	return 0;
}