#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<limits.h>
using namespace std;



 



int main(void){

    priority_queue<pair<int,bool>, vector<pair<int,bool>>, greater<pair<int,bool>> >p;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        p.push({x,false});
        p.push({y,true});
    }
    int curr_room=0,max_room=0;
    while(!p.empty()){
        if(!p.top().second)curr_room++;
        else curr_room--;
        max_room=max(max_room,curr_room);
        p.pop();
    }
    cout<<max_room<<endl;


    return 0;
}