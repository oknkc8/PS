#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, p, q;
map<ll, ll> mp;

ll f(ll x) {
	if (!x) return 1;
	if (mp.find(x) != mp.end()) return mp[x];

	return mp[x] = f(x / p) + f(x / q);
}

int main() {
	cin >> n >> p >> q;

	cout << f(n);

	return 0;
}