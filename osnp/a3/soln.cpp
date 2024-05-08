#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, m, lo, hi, ans = -1;
vector<ll> a; 

ll f(ll x) {
	ll ret = 0;
	for (ll p : a) {
		ret += max(0LL, p - x);
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	a.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	lo = 0, hi = 1e13;

	while (lo <= hi) {
		ll md = (lo + hi) >> 1;

		if (f(md) >= m) {
			ans = md;
			lo = md + 1;
		} else {
			hi = md - 1;
		}	
	}

	cout << ans << '\n';
}

/*
tc 1:
10 25
4 2 9 9 5 3 6 7 2 10 
--
3

tc 2:
5 5
2 7 2 9 5
-- 
5

tc 3:
5 25
2 7 2 9 5
--
0

tc 4:
5 125
2 7 2 9 5
-- 
-1
*/