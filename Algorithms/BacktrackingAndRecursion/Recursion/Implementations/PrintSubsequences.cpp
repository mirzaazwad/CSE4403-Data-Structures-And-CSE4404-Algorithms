#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

void PrintSubsequence(string s,string t){
    if(s.empty()){
        cout<<t<<endl;
        return;
    }
    PrintSubsequence(s.substr(1),t);
    PrintSubsequence(s.substr(1),t+s[0]);
    
    
}

int main()
{
    fastio;
    string s;
    cin>>s;
    PrintSubsequence(s,"");
    return 0;
}