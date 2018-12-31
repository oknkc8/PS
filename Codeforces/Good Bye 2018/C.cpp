#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> p;
vector<ll> ans;

int main() {
	int n;	cin >> n;

	for (int i = 1; i*i <= n; i++) {
		if (!(n%i)) {
			p.push_back(i);
			if (n / i != i) p.push_back(n / i);
		}
	}

	for (auto i : p) {
		ll t = 0, r = n / i;
		t = r + (r - 1)*r / 2 * i;
		ans.push_back(t);
	}
	sort(ans.begin(), ans.end());
	for (auto i : ans) cout << i << " ";

	return 0;
}