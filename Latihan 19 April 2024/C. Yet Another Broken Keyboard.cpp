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

ll subs(ll n) {
    return n * (n + 1) / 2;
}

void test_case() 
{
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<bool> exist(200, 0);
    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;
        exist[c] = 1;
    }

    ll ans = 0;

    for (int l = 0, r = 0; r <= n;) {
        if (r == n) {
            ans += subs(r - l);
            r++;
        }

        else if (!exist[s[r]]) {
            ans += subs(r - l);
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
    // cin >> tc;

    while (tc--) {
        test_case();
    }
}
