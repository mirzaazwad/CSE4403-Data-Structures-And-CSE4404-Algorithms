/*
*Author: Mirza Mohammad Azwad
*Institude: Islamic University of Technology
*/
#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
using namespace std;
 
#define ll long long
#define endl "\n"

bool sortbyCond(const pair<int, int>& a,
                const pair<int, int>& b)
{
    if (a.first != b.first)
        return (a.first > b.first);
    else
       return (a.second < b.second);
}
 
int main()
{
    vector<int>arr;
    int x;
    unordered_map<int,int>mp;
    cin>>x;
    while(x!=0){
        mp[x]++;
        cin>>x;
        if(x==0)break;
    }
    int siz=mp.size();
    pair<int,int>times[siz];
    int i=0;
    for(auto u:mp){
        times[i].first=u.second;
        times[i].second=u.first;
        i++;
    }
    sort(times,times+siz,sortbyCond);
    for(int i=0;i<10;i++){
        if(times[i].first==0)continue;
        if(times[i].second==1)cout<<times[i].second<<" occurs:  "<<times[i].first<<" time"<<endl;
        else cout<<times[i].second<<" occurs:  "<<times[i].first<<" times"<<endl;
    }



}