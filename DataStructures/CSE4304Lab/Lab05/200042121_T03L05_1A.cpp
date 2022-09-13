#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<limits.h>
using namespace std;



 



int main(void){

    priority_queue<int, vector<int>, greater<int> > p;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        p.push(x);
    }
    int count=0;
    while(p.size()>1){
        int value=p.top();
        p.pop();
        int value2=p.top();
        p.pop();
        count++;
        if(p.top()>=m){
            cout<<count<<endl;
            return 0;
        }
        
    }
    if(count!=m){
        cout<<-1<<endl;
    }



    return 0;
}