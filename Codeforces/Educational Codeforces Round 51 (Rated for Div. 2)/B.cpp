#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll a, b;	cin >> a >> b;
	cout << "YES\n";
	for (ll i = a; i <= b; i+=2) {
		cout << i << " " << i + 1 << endl;
	}

	return 0;
}