
#include <bits/stdc++.h>
using namespace std;
using ll =long long int;
void solve(){
    auto partOne=[&]()->void{
        string s;
        int num=50;
        int cnt=0;
        while(getline(cin,s)){
            char dir=s[0];
            int i=1;
            int steps=0;
            while(i<s.size()){
                steps=10*steps+(s[i]-'0');
                i++;
            }
            
            if(dir=='R'){
                 num+=steps;
            }else num-=steps;
            num=(num+100)%100;
            //cout<<num<<" ";
            if(num==0)cnt++;
        }
        cout<<cnt<<endl;
    };
    auto partTwo=[&]()->void{
            string s;
        int num=50;
        int cnt=0,x=0;
        while(getline(cin,s)){
            char dir=s[0];
            int i=1;
            int steps=0;
            while(i<s.size()){
                steps=10*steps+(s[i]-'0');
                i++;
            }
            
            if(dir=='R'){
                 num+=steps;
            }else num-=steps;
            int temp=num;
               //cout<<temp<<endl;
             if(temp>0) cnt+=temp/100;
               else {
                   while(temp<0 ){
                       temp+=100;
                       cnt++;
                   }
                   //cnt--;
               }
            num=(num+100)%100;
            //cout<<num<<" ";
            if(num==0){
                x++;
                cnt++;
            }
            
        }
        cout<<cnt-x<<endl;
    };
   // partOne();
    partTwo();
}
int main()
{
    solve();

    return 0;
}