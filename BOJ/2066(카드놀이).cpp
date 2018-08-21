#include<bits/stdc++.h>
using namespace std;

string v[9][5];
map<vector<int>, double> mp;

double f(vector<int> c) {
	int flag = 0;
	for (int i = 0; i < 9; i++) {
		if (c[i]) flag = 1;
	}
	if (!flag) return 1.0;
	
	if (mp.count(c)) return mp[c];
	double ret = 0.0;

	vector<pair<int, int>> vp;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (v[i][c[i]] != "" && v[j][c[j]] != "" && v[i][c[i]][0] == v[j][c[j]][0]) vp.push_back({ i,j });
		}
	}
	int cnt = vp.size();
	double p = 0;
	for (auto i : vp) {
		c[i.first]--, c[i.second]--;
		p += f(c);
		c[i.first]++, c[i.second]++;
	}
	if (cnt == 0) return mp[c] = 0.0;
	else return mp[c] = (p / (double)cnt);
}

int main() {
	for (int i = 0; i < 9; i++) for (int j = 1; j <= 4; j++) cin >> v[i][j];

	vector<int> a(9, 4);
	printf("%.7lf", f(a));

	return 0;
}