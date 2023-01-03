//link to problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045

#include<bits/stdc++.h>
using namespace std;

pair<pair<int,int>,int>gcd(int a,int b){
    static pair<pair<int,int>,int>res;
    if(b==0){
        res.first.first=1;
        res.first.second=0;
        res.second=a;
        return res;
    }
    int x1,y1;
    pair<pair<int,int>,int>d=gcd(b,a%b);
    x1=res.first.first,y1=res.first.second;
    res.first.first=y1;
    res.first.second=x1-y1*(a/b);
    return res;
}

int main(void){
    int a,b;
    while(cin>>a>>b){
        pair<pair<int,int>,int>g=gcd(a,b);
        cout<<g.first.first<<" "<<g.first.second<<" "<<g.second<<endl;
    }

}
