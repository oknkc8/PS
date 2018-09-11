#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<ll> q1, q2;

int main() {
	int n;	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a;	cin >> a;
		q1.push(a);
	}
	for (int i = 0; i < n; i++) {
		ll a;	cin >> a;
		q2.push(a);
	}

	ll a = 0, b = 0;
	for (int i = 0; i < 2 * n; i++) {
		ll x = q1.empty() ? 0 : q1.top(), y = q2.empty() ? 0 : q2.top();

		if (!(i % 2)) {
			if (x < y) q2.pop();
			else a += x, q1.pop();
		}
		else {
			if (x > y) q1.pop();
			else b += y, q2.pop();
		}
	}

	printf("%lld", a - b);

	return 0;
}