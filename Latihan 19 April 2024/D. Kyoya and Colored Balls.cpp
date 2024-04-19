/*
*    syxm1
*/

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;

const int mod = 1e9+7;

vector<ll> fac(1005, 1), inv(1005, 1);

ll binpow(ll a, ll x, const int mod)
{
    ll ret = 1;
    while (x) {
        if (x & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        x >>= 1;
    }
    return ret;
}

ll combinations(ll n, ll r) 
{
    if (n < r) return 0;
    return (((fac[n] * inv[r]) % mod) * inv[n - r]) % mod;
}

void test_case() 
{
    for (int i = 1; i <= 1000; i++) {
        fac[i] = (fac[i-1] * i) % mod;
    }

    for (int i = 1; i <= 1000; i++) {
        inv[i] = binpow(fac[i], mod - 2, mod);
    }

    int k;
    cin >> k;

    ll ans = 1, sum = 0;

    for (int i = 0; i < k; i++) {
        ll c;
        cin >> c;

        ans = (ans * combinations(c - 1 + sum, sum)) % mod;
        sum += c;
    }

    cout << ans << '\n';
}

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    // cin >> tc;

    while (tc--) {
        test_case();
    }
}
