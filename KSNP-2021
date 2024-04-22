#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define dbg(x) cerr << #x << " : " << x << '\n';

ll n, m, a, b, q, l;

ll cnt(double d) {
	ll ret = 0;
	for (ll i = 1; i <= n; i++) {
		ret += min((ll) m, max(0LL, (ll) (d * (a + i) - b)));
	} 
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> a >> b >> q;

	while (q--) {
		cin >> l;

		double lo = 0;
		double hi = 1e9;

		double val = 0;
		for (ll i = 0; i < 100; i++) {
			double md = (lo + hi) / 2.00;
			if (cnt(md) >= l) {
				val = md;
				hi = md;
			} else {
				lo = md;
			}
		}

		ll p = 0, q = 1;

		for (ll i = a+1; i <= a+n; i++) {
			ll r = val * i;
			if (r > b + m) continue;
			if (p * i < r * q) p = r, q = i;
		}
		
		ll gcd = __gcd(p, q);
		cout << p / gcd  << '/' << q / gcd << '\n';
	}
}
