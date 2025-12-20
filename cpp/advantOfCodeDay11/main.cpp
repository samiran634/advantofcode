

#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    map<string,vector<string>>adj;
    while (getline(cin, s)) {
    if (s.empty()) continue;

    string p = "";
    int i = 0;
    while (i < s.size() && s[i] != ':') {
        p += s[i];
        i++;
    }

    i++; 
    if (i < s.size() && s[i] == ' ') i++; 
    while (i < s.size()) {
        string c = "";
        while (i < s.size() && s[i] != ' ') {
            c += s[i];
            i++;
        }

        adj[p].push_back(c);

        while (i < s.size() && s[i] == ' ') i++;
    }
}
  
    auto partOne=[&] ()-> void{
        int cnt=0;
        stack<string>st;
        st.push("you");
       // set<string>vis;
       // vis.insert("you");
        while(st.empty()==false){
            string top=st.top();
            st.pop();
            if(top=="out")cnt++;
            for(auto ngb:adj[top]){
               
                    st.push(ngb);
                   // vis.insert(ngb);
                
            }
            
        }
        cout<<cnt<<endl;
         
    };
    auto partTwo=[&] ()-> void{
           
              int cnt=0;
        stack<pair<string,set<string>>>st;
        st.push({"svr",{"svr"}});
       // set<string>vis;
       // vis.insert("you");
        while(st.empty()==false){
            set<string> list=st.top().second;
            string top=st.top().first;
            st.pop();
            if(top=="out"){
                if(list.find("fft")!=list.end() && list.find("dac")!=list.end())cnt++;
            }
            for(auto ngb:adj[top]){
                    list.insert(ngb);
                    st.push({ngb,list});
                   // vis.insert(ngb);
                
            }
            
        }
        cout<<cnt<<endl;
    };
    // partOne();
     partTwo();
}
int main()
{
    solve();

    return 0;
}