#include<bits/stdc++.h>
using namespace std;

map<vector<int>, double> m;

double f(vector<int> v) {
	if (m.count(v)) return m[v];

	double ret = 0;
	int cnt = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] > v[j]) {
				vector<int> r(v);
				swap(r[i], r[j]);
				ret += f(r) + 1;
				cnt++;
			}
		}
	}

	return m[v] = (!cnt ? 0 : ret / cnt);
}

int main() {
	int n;	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);

	printf("%.7lf", f(v));

	return 0;
}