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

ll cnt(ll n, ll k) {
    // return 1 + ... + n-k+1
    if (n < k) return 0;
    return (n - k + 2) * (n - k + 1) / 2;
}

void test_case() 
{
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0; int l = 0;
     
    for (int r = 0; r <= n;) {
        if (r == n) {
            ans += cnt(r - l, k);
            r++;
        }

        else if (a[r] > q) {
            ans += cnt(r - l, k);
            r++, l = r;
        } 

        else {
            r++;
        }
    }

    cout << ans << '\n';
}

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;

    while (tc--) {
        test_case();
    }
}
