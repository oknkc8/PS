#include<bits/stdc++.h>
using namespace std;

int v[26];

int main() {
	int n, k;	cin >> n >> k;
	string str;	cin >> str;
	for (int i = 0; i < str.size(); i++) v[str[i] - 'A']++;

	int m = 1000000000;
	for (int i = 0; i < k; i++) m = min(m, v[i]);
	printf("%d", m*k);

	return 0;
}