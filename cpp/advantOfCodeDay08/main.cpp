
#include <bits/stdc++.h>
using namespace std;
using ll =long long int;

struct DSU {
	vector<int> parent, size;
	DSU(int n) : parent(n), size(n,1) {
		iota(parent.begin(), parent.end(), 0);
	}
	int find(int x) {
		return parent[x] == x ? x : parent[x] = find(parent[x]);
	}
	bool unite(int a,int b) {
		a = find(a);
		b = find(b);
		if(a == b) return false;
		if(size[a] < size[b]) swap(a,b);
		parent[b] = a;
		size[a] += size[b];
		return true;
	}
};

struct Edge {
	long long d2;
	int a, b;
	bool operator<(Edge const& other) const {
		return d2 < other.d2;
	}
};
void solve() {

	auto partOne=[&]()->void{
		long long x,y,z;

		vector<array<long long,3>> pts;
		// Read lines like: X,Y,Z
		while (cin >> x) {
			char comma;
			if(!(cin >> comma >> y >> comma >> z)) break;
			pts.push_back({x,y,z});
		}

		int n = (int)pts.size();
		if(n == 0) {
			cout << "0\n";
			return ;
		}

		// Build all pairwise edges (squared distances)
		vector<Edge> edges;
		edges.reserve((size_t)max(0LL, (long long)n*(n-1)/2));
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				long long dx = pts[i][0] - pts[j][0];
				long long dy = pts[i][1] - pts[j][1];
				long long dz = pts[i][2] - pts[j][2];
				long long d2 = dx*dx + dy*dy + dz*dz;
				edges.push_back({d2, i, j});
			}
		}

		sort(edges.begin(), edges.end());

		DSU dsu(n);

		// Process the 1000 shortest edges (or all edges if fewer than 1000)
		int to_take = 1000;
		int taken = 0;
		for(const auto &e : edges) {
			// For each of the shortest edges:
			dsu.unite(e.a, e.b); // union as side-effect; may return false if already same
			taken++;
			if(taken == to_take) break;
		}

		// After processing up to 1000 shortest edges, get component sizes
		unordered_map<int,long long> comp;
		comp.reserve(n*2);
		for(int i=0; i<n; i++) comp[dsu.find(i)]++;

		vector<long long> sizes;
		sizes.reserve(comp.size());
		for(auto &p : comp) sizes.push_back(p.second);
		sort(sizes.begin(), sizes.end(), greater<long long>());

		// Ensure we have at least 3 numbers (if not, treat missing ones as 1)
		while(sizes.size() < 3) sizes.push_back(1);

		long long ans = sizes[0] * sizes[1] * sizes[2];
		cout << ans << "\n";
	};
	auto partTwo=[&]()->void{
		vector<array<long long,3>> pts;
		long long x,y,z;

		while(cin >> x) {
			char c;
			cin >> c >> y >> c >> z;  // read X,Y,Z format
			pts.push_back({x,y,z});
		}

		int n = pts.size();
		vector<Edge> edges;
		edges.reserve((long long)n*(n-1)/2);

		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				long long dx = pts[i][0] - pts[j][0];
				long long dy = pts[i][1] - pts[j][1];
				long long dz = pts[i][2] - pts[j][2];
				long long d2 = dx*dx + dy*dy + dz*dz;
				edges.push_back({d2, i, j});
			}
		}

		sort(edges.begin(), edges.end());

		DSU dsu(n);

		int successful = 0;
		int need = n - 1;

		long long lastA = -1, lastB = -1;

		for(auto &e : edges) {
			if(dsu.unite(e.a, e.b)) {
				successful++;
				lastA = e.a;
				lastB = e.b;
				if(successful == need) break;
			}
		}

		long long ans = pts[lastA][0] * pts[lastB][0];
		cout << ans << "\n";

	};
	partTwo();

}
int main()
{
	solve();

	return 0;
}