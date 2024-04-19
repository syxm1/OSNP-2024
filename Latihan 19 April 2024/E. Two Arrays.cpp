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

vector<ll> fac(2000, 1), inv(2000, 1);

void init() {
    for (int i = 1; i < 2000; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
        inv[i] = binpow(fac[i], mod - 2, mod);
    }
}

ll c(ll n, ll r) {
    return (((fac[n] * inv[r]) % mod) * inv[n-r]) % mod;
}

void test_case() 
{
    init();

    ll n, m;
    cin >> n >> m;
    cout << c(n + 2 * m - 1, 2 * m) << '\n';
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
