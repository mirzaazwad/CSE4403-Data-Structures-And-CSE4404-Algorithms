/*
*Author: Mirza Mohammad Azwad
*Institude: Islamic University of Technology
In the name of Allah, the Lord of Mercy, the Giver of Mercy
*/
#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
using namespace std;
 
#define ll long long
#define endl "\n"
 

void solve(){
    string str;
    cin>>str;
    int len=str.length();
    stack<char>s;
    int ans=0;
    for(int i=0;i<len;i++){
        if(str[i]=='<'){
            s.push(str[i]);
        }
        else{
            if(str[i]=='>'){
                if(s.empty())break;
                s.pop();
            }
            if(s.empty()){
                ans=max(ans,i+1);
            }
        }
    }
    cout<<ans<<endl;
}


int main()
{
    fastio;
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
