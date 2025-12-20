#include <bits/stdc++.h>

using namespace std;
using ll=long long int;

bool isNumeric(const string &s) {
	return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}
void solve() {
	vector<string>inputs;
	string s;
	int col=-1;
	while(getline(cin,s)) {
		inputs.push_back(s);
		col=max(col,(int)inputs.back().size());
	}

	auto partOne=[&]()->void{
		string strops=inputs.back();
		vector<char>ops;
		for(int i=0; i<strops.size(); i++) {
			if(strops[i]==' ')continue;
			ops.push_back(strops[i]);
		}

		int n=ops.size();
		vector<vector<ll>>nums(n);




		for(int i=0; i<inputs.size()-1; i++) {
			string str=inputs[i];
			int j=0;
			int ind=0;
			while(j<str.size()) {
				string sub="";
				while(j<str.size()&&str[j]!=' ') {
					sub+=str[j];
					j++;
				}
				while(j<str.size()&& str[j]==' ')j++;
				if(isNumeric(sub)) {
					nums[ind].push_back(stoll(sub));
					// cout<<nums[ind].back()<<endl;
					ind++;
				}

			}
		}
		ll ans=0;
		// for(auto num:nums){
		//     for(auto j:num)cout<<j<<" ";
		//     cout<<endl;

		// }
		for(int i=0; i<ops.size(); i++) {
			if(ops[i]=='+') {
				ans+=accumulate(nums[i].begin(),nums[i].end(),0LL);
			} else {
				ll mul=1;
				for(int j=0; j<nums[i].size(); j++) {
					mul*=nums[i][j];
				}
				ans+=mul;
			}
		}
		cout<<ans<<endl;
	};

auto partTwo = [&]() -> void {
    ll ans = 0;
    int row = inputs.size();
    
    // 1. FIX: Find the maximum column width across ALL rows
    int col = 0;
    for(const auto& s : inputs) col = max(col, (int)s.length());

    char op = '\0';
    vector<ll> nums;

    // Helper to calculate and reset
    auto processBatch = [&]() {
        if (nums.empty()) return;
        if (op == '+') {
            ans += accumulate(nums.begin(), nums.end(), 0LL);
        } else {
            ll mul = 1;
            for (auto num : nums) mul *= num;
            ans += mul;
        }
        op = '\0';
        nums.clear();
    };

    for (int i = 0; i < col; i++) {
        ll num = 0;
        bool hasDigit = false; 

        for (int j = 0; j < row; j++) {
            // 2. FIX: Guard against short rows
            char currentChar = (i < inputs[j].size()) ? inputs[j][i] : ' ';

            if (currentChar != ' ') {
                if (currentChar == '*' || currentChar == '+') {
                    op = currentChar;
                } else {
                    num = num * 10 * 1LL + (currentChar - '0');
                    hasDigit = true;
                }
            }
        }

        if (hasDigit) {
            nums.push_back(num);
        } else {
            processBatch();
        }
    }

    // 3. FIX: Final Flush (Still required!)
    processBatch();

    cout << ans << endl;
};
	partOne();
	partTwo();
}
int main() {
	solve();
	return 0;
}