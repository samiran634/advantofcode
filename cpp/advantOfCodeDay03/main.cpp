
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
string best12(string &b) {
    int K = 12;
    int remove = b.size() - K;
    string st = "";

    for (char c : b) {
        while (!st.empty() && remove > 0 && st.back() < c) {
            st.pop_back();
            remove--;
        }
        st.push_back(c);
    }

    // If still long, trim
    st.resize(K);
    return st;
}


void solve(){
    vector<string>bt ;
    string s;
      // read until EOF
    while (getline(cin, s)) {
        if (s.size() == 0) continue;   // optional: skip empty lines
      
        bt.push_back(s);
    }
    
    auto partOne=[&]()->void{
        int ans=0;
        for(auto b:bt){
            int maxe=0;
            for(int i=0;i<b.size();i++){
                for(int j=i+1;j<b.size();j++){
                    int num=(b[i]-'0')*10+(b[j]-'0');
                    maxe=max(num,maxe);
                }
            }
            ans+=maxe;
        }
        cout<<ans<<endl;
    };
    auto partTwo=[&]()->void{
        ll ans=0;
    for(auto b:bt){
         string s = best12(b); 
      
          
        ans+=stoll(s);
    }
    cout<<ans<<endl;  
    };
    partOne();
    partTwo();
    
}

int main()
{
    solve();

    return 0;
}