#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

ll x, v[64] = { 1 }, ans=1;

int main() {
	cin >> v[1] >> x;
	v[1] %= mod;
	for (int i = 2; i < 64; i++) v[i] = (v[i - 1] * v[i - 1]) % mod;
	for (int i = 0; i < 63; i++)
		if (x & 1LL << i) ans = (ans*v[i + 1]) % mod;
	
	cout << ans;

	return 0;
}