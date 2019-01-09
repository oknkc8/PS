#include<bits/stdc++.h>
using namespace std;

struct info {
	int k, a, b;
	bool operator<(info p) const {
		return abs(a - b) > abs(p.a - p.b);
	}
};

int n, A, B, ans;
vector<info> v;

void fA(int x) {
	int tmp = min(A, v[x].k);
	ans += tmp * v[x].a;
	v[x].k -= tmp;
	A -= tmp;
}

void fB(int x) {
	int tmp = min(B, v[x].k);
	ans += tmp * v[x].b;
	v[x].k -= tmp;
	B -= tmp;
}

int main() {
	while (1) {
		cin >> n >> A >> B;
		if (!n) break;
		v.clear(), ans = 0;
		for (int i = 0; i < n; i++) {
			int k, da, db;	cin >> k >> da >> db;
			v.push_back({ k,da,db });
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			if (v[i].a <= v[i].b) fA(i), fB(i);
			else fB(i), fA(i);
		}

		cout << ans<<endl;
	}

	return 0;
}