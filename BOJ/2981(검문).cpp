#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (!b) return a;
	return gcd(b, a%b);
}

ll v[105], s[105];

int main() {
	int n;	cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i];

	sort(v, v + n);
	for (int i = 1; i < n; i++) s[i - 1] = v[i] - v[i - 1];

	sort(s, s + n - 1);
	ll g = s[0];
	for (int i = 1; i < n - 1; i++) g = gcd(g, s[i]);

	vector<ll> ans;
	for (ll i = 2; i*i <= g; i++) {
		if (g%i == 0) {
			ans.push_back(i);
			if (i != g / i) ans.push_back(g / i);
		}
	}
	ans.push_back(g);
	sort(ans.begin(), ans.end());
	for (auto i : ans) cout << i << " ";

	return 0;
}