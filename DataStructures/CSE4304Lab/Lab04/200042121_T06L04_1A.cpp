/*
*Author: Mirza Mohammad Azwad
*Institude: Islamic University of Technology
In the name of Allah, the Lord of Mercy, the Giver of Mercy
*/
#include<iostream>
#include<stack>
#include<queue>
#include<vector>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
using namespace std;
 
#define ll long long
#define endl "\n"
 
 int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int>s;
        queue<int>q;
        for(int i=0;i<students.size();i++)q.push(students[i]);
        for(int i=sandwiches.size()-1;i>=0;i--)s.push(sandwiches[i]);
        int n=sandwiches.size();
        int count=0;
        while(!s.empty()){
            if(s.top()==q.front()){
                s.pop();
                q.pop();
                n--;
                count=0;
            }
            else{
                int value=q.front();
                q.pop();
                q.push(value);
                count++;
            }
            if(count==n)break;
        }
        return count;
    }

void solve(){
    int n;
    cin>>n;
    vector<int>student(n),sandwich(n);
    for(int i=0;i<n;i++)cin>>student[i];
    for(int i=0;i<n;i++)cin>>sandwich[i];
    cout<<countStudents(student,sandwich);
}


int main()
{
    fastio;
    solve();
    return 0;
}