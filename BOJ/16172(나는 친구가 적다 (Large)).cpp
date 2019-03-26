#include<bits/stdc++.h>
using namespace std;

string t, p;
int n, m;
vector<int> pi, v;

void getpi() {
	pi = vector<int>(m, 0);

	int begin = 1, matched = 0;

	while (begin + matched < m) {
		if (p[begin + matched] == p[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) begin++;
			else {
				begin += (matched - pi[matched - 1]);
				matched = pi[matched - 1];
			}
		}
	}
}

int kmp() {
	int begin = 0, matched = 0;

	while (begin + matched < n) {
		if (t[begin + matched] == p[matched]) {
			matched++;
			if (matched == m) return 1;
		}
		else {
			if (matched == 0) begin++;
			else {
				begin += (matched - pi[matched - 1]);
				matched = pi[matched - 1];
			}
		}
	}
	
	return 0;
}

int main() {
	string tt;
	cin >> tt >> p;
	for (auto i : tt) {
		if (!(0 <= i - '0'&&i - '0' <= 9)) t += i;
	}
	n = t.length();
	m = p.length();

	getpi();
	printf("%d", kmp());

	return 0;
}