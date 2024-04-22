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
