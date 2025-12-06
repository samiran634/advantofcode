#include <bits/stdc++.h>

using namespace std;
using ll=long long int;

bool isNumeric(const string &s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}
void solve(){
    vector<string>inputs;
    string s;
    int col=-1;
    while(getline(cin,s)){
        inputs.push_back(s);
        col=max(col,(int)inputs.back().size());
    }
 
    auto partOne=[&]()->void{
       string strops=inputs.back();
    vector<char>ops;
    for(int i=0;i<strops.size();i++){
        if(strops[i]==' ')continue;
        ops.push_back(strops[i]);
    }

    int n=ops.size();
   vector<vector<ll>>nums(n);
 
 
 
 
    for(int i=0;i<inputs.size()-1;i++){
        string str=inputs[i];
        int j=0;
        int ind=0;
        while(j<str.size()){
            string sub="";
            while(j<str.size()&&str[j]!=' '){
                sub+=str[j];
                j++;
            }
            while(j<str.size()&& str[j]==' ')j++;
            if(isNumeric(sub)){
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
        for(int i=0;i<ops.size();i++){
            if(ops[i]=='+'){
                ans+=accumulate(nums[i].begin(),nums[i].end(),0LL);
            }else {
                ll mul=1;
                for(int j=0;j<nums[i].size();j++){
                    mul*=nums[i][j];
                }
                ans+=mul;
            }
        }
        cout<<ans<<endl;
    };
    
    auto partTwo=[&]()->void{
        ll ans=0;
        int row=inputs.size();
        char op='\0';
        vector<ll>nums;
        for(int i=0;i<col;i++){
            ll num=0;
            for(int j=0;j<row;j++){
                if(inputs[j][i]!=' '){
                    if(inputs[j][i]=='*'||inputs[j][i]=='+')op=inputs[j][i];
                    else{
                        num=num*10*1LL+(inputs[j][i]-'0');
                    }
                }
            }
            if(num>0)
            nums.push_back(num);
            else {
                if(op=='+'){
                    ans+=accumulate(nums.begin(),nums.end(),0LL);
                }else {
                    ll mul=1;
                   for(auto num:nums){
                       mul*=num;
                   } 
                   ans+=mul;
                }
                for(auto num:nums)cout<<num<<" ";
                cout<<endl;
                    op='\0';
                    nums.clear();
            }
        }
        cout<<ans<<endl;
        
    };
    partOne();
    partTwo();
}
int main(){
    solve();
    return 0;
}