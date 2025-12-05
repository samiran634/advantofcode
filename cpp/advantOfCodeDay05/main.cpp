
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
void solve(){
    vector<pair<ll,ll>>ranges;
    vector<ll>items;
      string s;

    // -------- Read ranges until blank line --------
    while (getline(cin, s)) {
        if (s == "") break;        // blank line → stop reading ranges
        
        ll a, b;
        char dash;
        stringstream ss(s);
        ss >> a >> dash >> b;      // format: "a-b"
        ranges.push_back({a, b});
    }

    // -------- Read items until EOF --------
    while (getline(cin, s)) {
        if (s == "") continue;     // ignore extra blank lines
        items.push_back(stoll(s));
    }
    
    auto mergeRange=[&]()->void{
        sort(ranges.begin(),ranges.end());
        vector<pair<ll,ll>>nr;
        int n=ranges.size();
        for(int i=0;i<n;i++){
            if(nr.size()==0)nr.push_back(ranges[i]);
            else {
                if(nr.back().second < ranges[i].first)nr.push_back(ranges[i]);
                else nr.back()={nr.back().first,max(nr.back().second,ranges[i].second)};
            }
        }
        ranges=nr;
    };
    
    mergeRange();
    auto partOne=[&]()->void{
        long long int ans=0;
        sort(items.begin(),items.end());
        for(auto item:items){
            for(auto [l,r]:ranges){
                if(l<=item && item<=r){
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    };
    auto partTwo=[&]()->void{
        ll ans=0;
      for(auto [l,r]:ranges){
          ans+=(r-l+1);
      }  
      cout<<ans<<endl;
    };
    partTwo();
    
}
int main()
{
    int t=1;
    while(t--){
        solve();
    }

    return 0;
}