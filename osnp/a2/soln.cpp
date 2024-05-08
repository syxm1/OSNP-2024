#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll b, c, d, ans = 0;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> b >> c >> d;

	if (c == d) {
		ans = max(0LL, b-d);
	} else {
		c -= d;
		for (ll i = 1; i * i <= c; i++) {
			if (c % i == 0) {
				ll x = c/i, y = i;
				if (x <= b && x >= 1 && d < x) {ans++;}
				if (y != x && y <= b && y >= 1 && d < y) {ans++;}
			}
		}
	}

	cout << ans << '\n';
}

/*
100 13 3 -> 2
9 9 0 -> 3
77 42 42 -> 35
7 42 42 -> 0
25 8420 20 -> 3
*/