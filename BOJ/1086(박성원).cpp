#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> num;
int n, k, d[55];
ll dp[1 << 15][105];
vector<int> v, l;

ll f(int check, int x) {
	ll &ret = dp[check][x];
	if (ret != -1) return ret;
	if (check + 1 == 1 << n) return !x;

	ret = 0;
	for (int i = 0; i < n; i++) {
		if (!(check & (1 << i))) ret += f(check | (1 << i), (x*d[l[i]] + v[i]) % k);
	}
	
	return ret;
}

ll gcd(ll a, ll b) {
	if (a < b) swap(a, b);
	if (!b) return a;
	return gcd(b, a%b);
}

int main() {
	cin >> n;	num.resize(n), v.resize(n), l.resize(n);
	for (int i = 0; i < n; i++)	cin >> num[i];
	cin >> k;
	
	for (int i = 0; i < n; i++) {
		l[i] = num[i].size();
		for (int j = 0; j < num[i].size(); j++)	v[i] = (v[i] * 10 + num[i][j] - '0') % k;
	}
	d[0] = 1 % k;
	for (int i = 1; i <= 50; i++) d[i] = d[i - 1] * 10 % k;

	memset(dp, -1, sizeof(dp));
	ll ans = f(0, 0);
	if (ans == 0) printf("0/1");
	else {
		ll x = 1;
		for (int i = 2; i <= n; i++) x *= i;
		ll g = gcd(ans, x);
		printf("%lld/%lld", ans / g, x / g);
	}

	return 0;
}