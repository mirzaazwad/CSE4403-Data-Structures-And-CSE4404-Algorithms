#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<limits.h>
using namespace std;



 



int main(void){

    priority_queue<int> p;
    int n;
    while(cin>>n,n!=-1){
        p.push(n);
    }
    int count=0;
    while(p.size()>1){
        int x=p.top();
        p.pop();
        int y=p.top();
        p.pop();
        if(x!=y){
            p.push(abs(y-x));
        }

        
    }
    if(p.empty()){
        cout<<0<<endl;
        return 0;
    }
    cout<<p.top()<<endl;



    return 0;
}