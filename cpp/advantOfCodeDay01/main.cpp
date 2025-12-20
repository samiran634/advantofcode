
#include <bits/stdc++.h>
using namespace std;
using ll =long long int;
void solve() {
	auto partOne=[&]()->void{
		string s;
		int num=50;
		int cnt=0;
		while(getline(cin,s)) {
			char dir=s[0];
			int i=1;
			int steps=0;
			while(i<s.size()) {
				steps=10*steps+(s[i]-'0');
				i++;
			}

			if(dir=='R') {
				num+=steps;
			} else num-=steps;
			num=(num+100)%100;
			//cout<<num<<" ";
			if(num==0)cnt++;
		}
		cout<<cnt<<endl;
	};
	auto partTwo = [&]()->void {
		string s;
		ll num = 50;
		ll cnt = 0;

		while (getline(cin, s)) {
			char dir = s[0];

			ll steps = 0;
			for (int i = 1; i < s.size(); i++) {
				steps = steps * 10 + (s[i] - '0');
			}

			ll delta = (dir == 'L') ? -1 : 1;

			for (int i = 0; i < steps; i++) {
				num = (num + delta) % 100;
				if (num < 0) num += 100;

				if (num == 0) cnt++;
			}
		}

		cout << cnt << endl;
	};

	// partOne();
	partTwo();
}
int main()
{
	solve();

	return 0;
}