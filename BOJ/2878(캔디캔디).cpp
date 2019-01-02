#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;


ull  sum;
vector<ull> v;

int main() {
	ull m, n;	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		ull a;	cin >> a;
		sum += a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	sum -= m;
	ull c = n, ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] < sum / c) {
			ans = (ans + v[i] * v[i]);
			sum -= v[i];
		}
		else {
			ull t = sum / c;
			ans = (ans + t * t);
			sum -= t;
		}
		c--;
	}

	cout << ans;

	return 0;
}