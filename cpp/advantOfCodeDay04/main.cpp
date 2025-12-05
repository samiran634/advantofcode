#include <bits/stdc++.h>
using namespace std;
void print(vector<string>m){
    for(auto s:m)cout<<s<<endl;
}

void solve(){
    vector<string>matrix;
    // i want to take input till there is not input 
       string s;
    
    // Read until EOF
    while (getline(cin, s)) {
        if (s.size() == 0) continue;  // skip empty lines if any
        matrix.push_back(s);
    }
    //print(matrix);
    long long int ans=0;
    int row=matrix.size(),col=matrix[0].size();
    vector<pair<int,int>>dirs={
        {-1,-1},
        {-1,0},
        {-1,1},
        {1,-1},
        {1,0},
        {1,1},
        {0,-1},
        {0,1},
    };
    auto is_valid=[&](int x,int y)->bool{
        return x>=0&&y>=0&&x<row&&y<col&&matrix[x][y]=='@';  
    };
    function<void()>partOnelogic=[&]()->void{
            for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]=='@'){
                int x=i;
                int y=j;
                int cnt=0;
                for(auto [dx,dy]:dirs){
                    int nx=x+dx;
                    int ny=y+dy;
                    if(is_valid(nx,ny)){
                        cnt++;
                           
                    }
                }
                if(cnt<4){
                    ans++;
                }
            }
        }
    }

    };
    
    function<void()> partTwologic=[&]() ->void{
    int f=0;
    //vector<pair<int,int>>inds;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]=='@'){
                int x=i;
                int y=j;
                int cnt=0;
                for(auto [dx,dy]:dirs){
                    int nx=x+dx;
                    int ny=y+dy;
                    if(is_valid(nx,ny)){
                        cnt++;
                           
                    }
                }
                if(cnt<4){
                    ans++;
                    matrix[x][y]='#';
                    f=1;
                }
            }
        }
    }

    if(f){
        partTwologic();
    }
};

    
    
    partOnelogic();
    cout<<ans<<endl;
    ans=0;
    partTwologic();
    
    cout<<ans<<endl;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
   // cin >> t;
    while (t--) {
       solve();
    }

    return 0;
}
