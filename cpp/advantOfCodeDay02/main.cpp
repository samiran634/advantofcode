#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	// read whole input (possibly multi-line)
	string s, temp;
	while (getline(cin, temp)) s += temp;

	vector<pair<ll,ll>> range;
	int i = 0, n = s.size();

	while (i < n) {
		ll x = 0, y = 0;

		// read x
		while (i < n && isdigit(s[i])) {
			x = x * 10 + (s[i] - '0');
			i++;
		}

		if (i >= n || s[i] != '-') break;
		i++; // skip '-'

		// read y
		while (i < n && isdigit(s[i])) {
			y = y * 10 + (s[i] - '0');
			i++;
		}

		range.push_back({x, y});

		// skip commas, spaces, newlines
		while (i < n && !isdigit(s[i]))
			i++;
	}
	auto  partOne=[&]()->void{
		auto check = [&](ll val) {
			string num = to_string(val);
			int len = num.size();
			if (len % 2) return false;

			int half = len / 2;
			return num.substr(0, half) == num.substr(half, half);
		};

		ll ans = 0;
		for (auto [l, r] : range)
			for (ll i = l; i <= r; i++)
				if (check(i)) ans += i;

		cout << ans << endl;
	};

	auto partTwo=[&]()->void{
		auto check = [&](ll val) {
			string s = to_string(val);
			string t = s + s;
			return (t.substr(1, t.size() - 2).find(s) != string::npos);
		};


		ll ans = 0;
		for (auto [l, r] : range)
			for (ll i = l; i <= r; i++)
				if (check(i)) ans += i;

		cout << ans << endl;
	};
	partTwo();
	partOne();


}

int main() {
	solve();
}
