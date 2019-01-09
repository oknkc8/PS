#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;	cin >> a >> b;
		v.push_back({ b,a });
	}

	sort(v.begin(), v.end());

	int ans = 1, t = v[0].first;
	for (int i = 1; i < v.size(); i++) {
		if (t <= v[i].second) {
			ans++;
			t = v[i].first;
		}
	}

	cout << ans;

	return 0;
}