#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll b, n;
string s;
vector<ll> y, dp;

const int mod = 1e9+7;

ll solve(ll i) {
	if (i == n) {
		return 1;
	}

	else if (dp[i] != -1) {
		return dp[i];
	}

	ll ret = 0;

	if (y[i] == 0) {
		ret += solve(i + 1);
		ret %= mod;
	}
	else {
		for (ll j = i, s = 0; j < n && s < b; j++, s*=10) {
			s += y[j];
			if (s < b) {
				ret += solve(j + 1);
				ret %= mod;
			} 
			else {
				break;
			}
		}
	}

	return dp[i] = ret;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> b >> s;

	for (char c : s) {
		y.push_back(c - '0');
	}

	n = y.size();

	dp.resize(n, -1);

	cout << solve(0) << '\n';
}

/*
tc1:
16
114240
--
3

tc2:
4
114240
--
0

tc3:
10
0
--
1

tc4:
10
1001
--
1

tc5:
1000000
123456789123456789123456789123456789
--
649774399
*/