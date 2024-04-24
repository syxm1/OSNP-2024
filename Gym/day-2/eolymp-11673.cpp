// Maximum Palindrome

#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	const int n = s.length();

	int k;
	cin >> k;

	int diff = 0;

	for (int i = 0; i < n/2; i++) {
		diff += (s[i] != s[n - i - 1]);
	}

	if (diff > k) {
		cout << ":(\n";
		return 0;
	}

	vector<bool> done((n + 1) / 2, 0);

	for (int i = 0; i < n/2; i++) {
		if (s[i] != s[n - i - 1]) {
			if (s[i] > s[n - i - 1]) {
				s[n - i - 1] = s[i];
			} else {
				s[i] = s[n - i - 1];
			}
			k--, done[i] = 1;
		}
	}

	for (int i = 0; i < n/2 && k > 0; i++) {
		if (s[i] == 'z') continue;
		if (done[i]) {
			s[i] = 'z', s[n - i - 1] = 'z', k--;
		} else if (k >= 2) {
			s[i] = 'z', s[n - i - 1] = 'z', k -= 2;
		}
	}

	if (k && (n & 1)) s[n/2] = 'z';

	cout << s << '\n';
}
