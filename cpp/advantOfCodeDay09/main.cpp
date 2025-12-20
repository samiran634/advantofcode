
#include <bits/stdc++.h>
using namespace std;
using ll =long long int;
struct points {
	ll x;
	ll y;
};
void solve() {
	vector<points>inputs;
	string s;
	while(getline(cin,s)) {
		ll x=0;
		ll y=0;
		int i=0;
		while(s[i]!=',') {
			x=10*x+(s[i]-'0');
			i++;
		}
		i++;
		while(i<s.size()) {
			y=10*y+(s[i]-'0');
			i++;
		}
		points point;
		point.x=x;
		point.y=y;
		inputs.push_back(point);

	}
	// for(auto input:inputs){
	//     cout<<input.x<<" "<<input.y<<endl;
	// }
	auto partOne=[&]()->void{
		ll ans=0;
		int n=inputs.size();
		for(int i=0; i<n; i++) {
			points p1=inputs[i];
			for(int j=i; j<n; j++) {
				points p2=inputs[j];
				if(p2.x==p1.x||p1.y==p2.y)ans=max(ans,abs(p1.x-p1.x)+abs(p1.y-p2.y));
				else {
					ll w=abs(p1.x-p2.x)+1;
					ll h=abs(p1.y-p2.y)+1;
					ans=max(ans,1LL*w*h);
				}
			}
		}
		cout<<ans<<endl;
	};
	auto partTwo = [&]() -> void {
		int n = inputs.size();
		set<ll> xset, yset;

		// Collect x and y coordinates for compression
		for (auto &p : inputs) {
			xset.insert(p.x);
			xset.insert(p.x + 1);
			yset.insert(p.y);
			yset.insert(p.y + 1);
		}

		vector<ll> xlst(xset.begin(), xset.end());
		vector<ll> ylst(yset.begin(), yset.end());

		map<ll, int> xmap, ymap;
		for (int i = 0; i < xlst.size(); i++) xmap[xlst[i]] = i;
		for (int i = 0; i < ylst.size(); i++) ymap[ylst[i]] = i;

		// Create grid
		vector<vector<int>> grid(xlst.size(), vector<int>(ylst.size(), 0));

		for (int i = 0; i < n; i++) {
			ll x1 = inputs[i].x, y1 = inputs[i].y;
			ll x2 = inputs[(i + 1) % n].x, y2 = inputs[(i + 1) % n].y;

			int cx1 = xmap[x1], cy1 = ymap[y1];
			int cx2 = xmap[x2], cy2 = ymap[y2];

			if (cx1 != cx2) {
				if (cx1 > cx2) swap(cx1, cx2);
				assert(cy1 == cy2);
				grid[cx1][cy1] |= 1;
				grid[cx2][cy1] |= 2;
				for (int x = cx1 + 1; x < cx2; x++) grid[x][cy1] |= 3;
			}
			if (cy1 != cy2) {
				if (cy1 > cy2) swap(cy1, cy2);
				assert(cx1 == cx2);
				grid[cx1][cy1] |= 4;
				grid[cx1][cy2] |= 8;
				for (int y = cy1 + 1; y < cy2; y++) grid[cx1][y] |= 12;
			}
		}

		// Build real grid using XOR sweep
		vector<vector<bool>> realgrid(xlst.size(), vector<bool>(ylst.size(), false));
		for (int i = 0; i < xlst.size(); i++) {
			int nxt = 0;
			for (int j = 0; j < ylst.size(); j++) {
				realgrid[i][j] = (nxt > 0 || grid[i][j] > 0);
				nxt ^= grid[i][j];
			}
			assert(nxt == 0);
		}

		// 2D prefix sum
		vector<vector<int>> pref(xlst.size() + 1, vector<int>(ylst.size() + 1, 0));
		for (int i = 0; i < xlst.size(); i++) {
			for (int j = 0; j < ylst.size(); j++) {
				pref[i + 1][j + 1] = realgrid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
			}
		}

		// Check all pairs of points
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				ll x1 = min(inputs[i].x, inputs[j].x);
				ll x2 = max(inputs[i].x, inputs[j].x);
				ll y1 = min(inputs[i].y, inputs[j].y);
				ll y2 = max(inputs[i].y, inputs[j].y);

				int cx1 = xmap[x1], cx2 = xmap[x2];
				int cy1 = ymap[y1], cy2 = ymap[y2];

				int total = pref[cx2 + 1][cy2 + 1] - pref[cx2 + 1][cy1] - pref[cx1][cy2 + 1] + pref[cx1][cy1];
				if (total == (cx2 - cx1 + 1) * (cy2 - cy1 + 1)) {
					ans = max(ans, (x2 - x1 + 1) * (y2 - y1 + 1));
				}
			}
		}

		cout << ans << endl;
	};

	partOne();
	partTwo();
}
int main()
{
	solve();

	return 0;
}