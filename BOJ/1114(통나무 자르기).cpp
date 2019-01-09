#include<bits/stdc++.h>
using namespace std;

int l, k, c;
int v[10005];
pair<int, int> ans;

bool check(int x) {
	int s = 0, cnt = 0, idx = 0;
	for (int i = 1; i <= k + 1; i++) {
		s += (v[i] - v[i - 1]);
		if (v[i] - v[i - 1] > x) return 0;
		if (s > x){
			cnt++;
			s = 0, i--;
			idx = i;
			if (cnt > c) return 0;
		}
	}
	ans = { x,idx };
	if (cnt < c) ans = { x,k };
	return 1;
}

int main() {
	cin >> l >> k >> c;
	for (int i = 1; i <= k; i++) {
		cin >> v[i];
		v[i] = l - v[i];
	}
	sort(v + 1, v + k + 1);
	v[k + 1] = l;

	int h = 0, t = l;
	while (h <= t) {
		int m = (h + t) / 2;
		if (check(m)) {
			t = m - 1;
		}
		else {
			h = m + 1;
		}
	}

	cout << ans.first << " " << l - v[ans.second];

	return 0;
}