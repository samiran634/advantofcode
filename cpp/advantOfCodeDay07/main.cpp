
#include <bits/stdc++.h>
using namespace std;
using ll =long long int;
void solve() {
	string s;
	vector<string>inputs;
	while(getline(cin,s)) {
		inputs.push_back(s);
	}

	auto partOne=[&]()->void{
		int row=inputs.size(),col=inputs[0].size();
		int split=0;

		auto is_valid=[&](int x,int y)->bool{
			return x<row&&y<col&&x>=0&&y>=0&&inputs[x][y]=='.';
		};
		vector<pair<int,int>>dirs={
			{0,1},
			{0,-1}
		};

		for(int i=1; i<row; i++) {
			for(int j=0; j<col; j++) {
				if(inputs[i-1][j] =='S'||inputs[i-1][j]=='|') {
					if(inputs[i][j]=='^') {
						for(auto [r,c]:dirs) {
							int nx=i+r;
							int ny=j+c;
							if(is_valid(nx,ny)) {
								inputs[nx][ny]='|';
							}
						}
						split++;
					} else {
						inputs[i][j]='|';
					}
				}
			}
		}
		cout<<split<<endl;
	};

auto partTwo = [&](){
    int R = inputs.size();
    int C = inputs[0].size();

    vector<vector<ll>> dp(R, vector<ll>(C, 0));
    int sr=-1, sc=-1;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(inputs[i][j]=='S'){
                sr = i;
                sc = j;
                break;
            }
        }
    }
 
    dp[sr+1][sc] = 1;
   
    for(int r = sr+1; r < R-1; r++){   
        for(int c = 0; c < C; c++){
            long long ways = dp[r][c];
            if(ways == 0) continue;

            if(inputs[r][c] == '^') {
                // split left
                if(c-1 >= 0)
                    dp[r+1][c-1] += ways;

                // split right
                if(c+1 < C)
                    dp[r+1][c+1] += ways;
            }
            else {
                // go straight
                dp[r+1][c] += ways;
            }
        }
    }

    // count all timelines on last row
    long long total = 0;
    for(int c=0;c<C;c++)
        total += dp[R-1][c];

    cout << total << endl;
};


	// partOne();

	partTwo();
}
int main()
{
	solve();

	return 0;
}