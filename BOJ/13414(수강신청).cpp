#include<bits/stdc++.h>
using namespace std;

map<string, int> m;
vector<pair<int, string>> v;

int main() {
	int k, l, c = 0;	cin >> k >> l;
	while (l--) {
		char s[15];	scanf("%s", s);
		string str = string(s);
		m[str] = ++c;
	}
	for (auto i : m) v.push_back({ i.second,i.first });
	sort(v.begin(), v.end());

	int s = v.size();
	for (int i = 0; i < min(k, s); i++) {
		for (int j = 0; j < v[i].second.size(); j++) printf("%c", v[i].second[j]);
		printf("\n");
	}

	return 0;
}