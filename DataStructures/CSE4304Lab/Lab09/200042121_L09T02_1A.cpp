//In the name of Allah, The Lord of Mercy, The Giver of Mercy
//Author: Mirza Mohammad Azwad
//Institution: Islamic University of Technology
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#define ll int64_t
#define short int16_t
#define int int32_t
#define endl "\n"
 
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
 

namespace Problem{
    class Program{
        private:
            vector<int>nums;
            int target;
        public:
            Program(int t=1){
                for(int i=1;i<=t;i++){
                    takeInput();
                    solve();
                    clearSpace();
                }
            }
 
            void takeInput(){
                int n;
                while(cin>>n,n!=-1){
                    nums.push_back(n);
                }
                cin>>target;
            }
 
            void clearSpace(){
                nums.clear();
            }

            vector<pair<int,int>> getAllPairs(){
                vector<pair<int,int>>ans;
                unordered_set<int>s;
                for(int &i:nums){
                    auto it=s.find(target-i);
                    if(it!=s.end()){
                        ans.emplace_back(i,target-i);
                        s.erase(it);
                    }
                    else s.insert(i);
                }
                return ans;
            }

            void solve(){
                vector<pair<int,int>>ans=getAllPairs();
                if(ans.size()==0){
                    cout<<"No pairs found"<<endl;
                    return;
                }
                for(int i=0;i<ans.size()-1;i++){
                    cout<<"("<<ans[i].first<<","<<ans[i].second<<"), ";
                }
                cout<<"("<<ans.back().first<<","<<ans.back().second<<")";
                cout<<endl;
            }
    };
}
signed main()
{
    fastio;
    Problem::Program program=Problem::Program();
    return 0;
}