/*
*Author: Mirza Mohammad Azwad
*Institude: Islamic University of Technology
In the name of Allah, the Lord of Mercy, the Giver of Mercy
*/
#include<iostream>
#include<queue>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
using namespace std;
 
#define ll long long
#define endl "\n"
 
queue<int>q;
int ping(int t) {
        q.push(t);
        while(q.size() >= 1 && q.front() < t-3000){
            q.pop();
        }
        
        
        return q.size();
    }

int main(void){
    cout<<ping(1)<<endl;
    cout<<ping(2)<<endl;
    cout<<ping(3)<<endl;
    cout<<ping(4)<<endl;
    cout<<ping(3001)<<endl;
    cout<<ping(3002)<<endl;
    cout<<ping(3003)<<endl;
    cout<<ping(6003)<<endl;
    cout<<ping(10003)<<endl;
    return 0;
}