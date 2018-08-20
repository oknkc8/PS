#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll v[8][8] = {
	0,1,1,0,0,0,0,0,
	1,0,1,1,0,0,0,0,
	1,1,0,1,0,1,0,0,
	0,1,1,0,1,1,0,0,
	0,0,0,1,0,1,1,0,
	0,0,1,1,1,0,0,1,
	0,0,0,0,1,0,0,1,
	0,0,0,0,0,1,1,0
}, c[8][8];

int main() {
	int n;	scanf("%d", &n);
	for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) c[i][j] = v[i][j];

	vector<ll> t;
	while(n>1){
		t.push_back(n);
		if (n & 1) n--;
		else n /= 2;
	}

	for (int i = t.size() - 1; i >= 0; i--) {
		ll m[8][8] = { 0 };
		if (t[i] & 1) {
			for(int i=0;i<8;i++){
				for (int j = 0; j < 8; j++) {
					for (int k = 0; k < 8; k++) {
						m[i][j] += v[i][k] * c[k][j];
					}
				}
			}
		}
		else {
			for (int i = 0; i<8; i++) {
				for (int j = 0; j < 8; j++) {
					for (int k = 0; k < 8; k++) {
						m[i][j] += c[i][k] * c[k][j];
					}
				}
			}
		}
		for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) c[i][j] = m[i][j] % mod;
	}

	printf("%lld", c[0][0]);

	return 0;
}