#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define SIZE 200000
#define Min 0
#define Max 99999999
using namespace std;



int main(void){
    string x;
    cin>>x;
    vector<int>x_ix;
    int Size=x.length();

    for(int i=0;i<Size;i++){
        if(x[i]=='x')x_ix.push_back(i);
    }
    queue<pair<int,int>>anq;
    if(x_ix.empty())anq.push({0,0});
    for(auto u:x_ix){
        int coeff=0;
        int i=u-1;
        stack<char>s;
        while(i>=0 && isdigit(x[i])){
            s.push(x[i]);i--;
        }
        int sign=1;
        if(i>=0 && (x[i]=='-'||x[i]=='+')){
            if(x[i]=='+')sign=1;
            else sign=-1;
        }
        while(!s.empty()){
            coeff=coeff*10+(s.top()-'0');s.pop();
        }
        if(!coeff){
                coeff=1*sign;
        }
        else coeff=coeff*sign;
        int power=0;
        i=u+1;
         sign=1;
        if(i<Size && (x[i]=='-'||x[i]=='+')){
            if(x[i-1]=='+')sign=1;
            else sign=-1;
        }
        while(i<Size && isdigit(x[i])){
            power=power*10+(x[i]-'0');i++;
        }
        if(!power){
                power=1;
        }
        else power=power*sign;
        anq.push({coeff*power,power-1});
    }
    string ans="";
    while(!anq.empty()){
        int coeff=anq.front().first;
        int power=anq.front().second;
        if(ans==""){
                if(power==0)ans=ans+to_string(coeff);
                else if(power==1)ans=ans+to_string(anq.front().first)+"x";
                else ans=ans+to_string(anq.front().first)+"x"+to_string(anq.front().second);
        }
        else{
            if(anq.front().first<0){
                    if(power==0)ans=ans+to_string(coeff);
                    else if(power==1)ans=ans+to_string(anq.front().first)+"x";
                    else ans=ans+to_string(anq.front().first)+"x"+to_string(anq.front().second);
            }
            else{
                    if(power==0)ans=ans+"+"+to_string(coeff);
                    else if(power==1)ans=ans+"+"+to_string(anq.front().first)+"x";
                    else ans=ans+"+"+to_string(anq.front().first)+"x"+to_string(anq.front().second);
            }
        }
        anq.pop();
    }
    cout<<ans<<endl;


}
