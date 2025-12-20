#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto solve = [&](){
        auto partOne = [&](){
            int ans = 0;
            string s;

            while (getline(cin, s)){
                if (s.empty()) continue;

                // ------------------------
                // 1. Parse goal pattern
                // ------------------------
                string goal = "";
                int i = 0;
                while (s[i] != '[') i++;
                i++;
                while (s[i] != ']') {
                    goal += s[i];
                    i++;
                }
                int L = goal.size();

                // Convert goal to mask
                int goalMask = 0;
                for (char c : goal) {
                    goalMask = (goalMask << 1) | (c == '#');
                }

                // ------------------------
                // 2. Parse operations
                // ------------------------
                vector<int> ops;
                while (i < s.size() && s[i] != '{') {
                    if (s[i] == '(') {
                        i++;
                        int mask = 0;
                        while (s[i] != ')') {
                            int num = 0;
                            while (isdigit(s[i])) {
                                num = num * 10 + (s[i] - '0');
                                i++;
                            }
                            // toggle bit -> from left: bit = L - 1 - num
                            mask |= (1 << (L - 1 - num));

                            if (s[i] == ',') i++;
                        }
                        ops.push_back(mask);
                    }
                    i++;
                }

                // ------------------------
                // 3. BFS to find minimum operations
                // ------------------------
                vector<int> dist(1 << L, -1);
                queue<int> q;

                int start = 0;
                dist[start] = 0;
                q.push(start);

                int best = 0;

                while (!q.empty()){
                    int cur = q.front(); q.pop();

                    if (cur == goalMask) {
                        best = dist[cur];
                        break;
                    }

                    for (int op : ops){
                        int nxt = cur ^ op;
                        if (dist[nxt] == -1){
                            dist[nxt] = dist[cur] + 1;
                            q.push(nxt);
                        }
                    }
                }

                ans += best;
            }

            cout << ans << "\n";
        };

        partOne();
    };

    solve();
    return 0;
}
