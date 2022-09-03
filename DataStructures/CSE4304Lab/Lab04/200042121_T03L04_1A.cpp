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
    queue<int>q1;
    queue<int>q2;
    
    void push_s(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int>temp;
        temp=q1;
        q1=q2;
        q2=temp;
    }
    
    int pop_s() {
            int value=q1.front();
            q1.pop();
            return value;
    }
    
    int top_s() {
        return q1.front();
    }
    
    bool empty_s() {
        if(q1.empty())return true;
        else return false;
    }

void solve(){
    push_s(10);
    cout << top_s() << endl;
    push_s(20);
    cout << top_s() << endl;
    pop_s();
    cout << top_s() << endl;
    push_s(100);
    cout << top_s() << endl;
    cout << empty_s() << endl;
    pop_s();
    pop_s();
    cout << empty_s() << endl;

}
int main()
{
    fastio;
    solve();
    return 0;
}