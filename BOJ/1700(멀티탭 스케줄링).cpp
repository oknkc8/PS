#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	int v[105], c[105] = { 0 }, f[105] = { 0 };
	//map<pair<int, int>, int> m;
	vector<int> a;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> v[i];
		//c[v[i]]++;
		f[i + 1] = -1;
	}

	int ans = 0;
	for (int i = 0; i < k; i++) {
		if (!c[v[i]]) {
			if (a.size() < n) {
				a.push_back(v[i]);
				int m = 1e9;
				for (int j = i+1; j < k; j++) {
					if (v[i] == v[j]) {
						m = j;
						break;
					}
				}
				f[v[i]] = m;
				c[v[i]] = 1;
			}
			else {
				int m = -1, idx;
				for (int j = 0; j < a.size(); j++) {
					if (m < f[a[j]]) m = f[a[j]], idx = j;
				}
				c[a[idx]] = 0;
				a.erase(a.begin()+idx);
				ans++;
			
				m = 1e9;
				for (int j = i+1; j < k; j++) {
					if (v[i] == v[j]) {
						m = j;
						break;
					}
				}
				f[v[i]] = m;
				c[v[i]] = 1;
				a.push_back(v[i]);
			}
		}
		else {
			int m = 1e9;
			for (int j = i + 1; j < k; j++) {
				if (v[i] == v[j]) {
					m = j;
					break;
				}
			}
			f[v[i]] = m;
		}
	}

	cout << ans;

	return 0;
}