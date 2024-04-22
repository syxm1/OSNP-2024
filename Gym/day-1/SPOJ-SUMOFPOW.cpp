#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void test_case() {
	ll n, x, y;
	cin >> x >> y >> n;
	
	ll ans[n+1];

	ans[0] = 2;
	ans[1] = x;

	for (int i = 2; i <= n; i++) {
		ans[i] = ans[i-1] * x - ans[i-2] * y;
	}

	cout << ans[n] << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;

	while(tc--) {
		test_case();
	}
}

/*
definisikan ans[n] := (p^n) + (q^n), x = p+q, y = pq.
(p^(n-1) + q^(n-1)) * (p + q) = (p^n) + (q^n) + p^(n-1) * q + p * q^(n-1)
				(p^n) + (q^n) = (p^(n-1) + q^(n-1)) * (p + q) - (p^(n-1) * q + p * q^(n-1))
                (p^n) + (q^n) = (p^(n-1) + q^(n-1)) * (p + q) - (p^(n-2) + q^(n-2)) * pq
sehingga diperoleh recurrence relation : ans[n] = ans[n-1] * x - ans[n-2] * y,
dengan base case:
ans[0] = p^0 + q^0 = 1 + 1 = 2
ans[1] = p + q = x
*/
