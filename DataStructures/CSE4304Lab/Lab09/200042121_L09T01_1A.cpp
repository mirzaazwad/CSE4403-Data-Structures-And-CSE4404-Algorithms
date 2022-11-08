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
            vector<int>arr;
            vector<int>sub;
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
                    arr.push_back(n);
                }
                while(cin>>n,n!=-1){
                    sub.push_back(n);
                }
            }
 
            void clearSpace(){
                arr.clear();
                sub.clear();
            }

            bool isSubset(unordered_set<int>s){
                for(int &i:sub){
                    if(s.find(i)==s.end()){
                        return false;
                    }
                }
                return true;
            }

            void solve(){
                unordered_set<int>s;
                for(int &i:arr){
                    s.insert(i);
                }
                if(isSubset(s)){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"No"<<endl;
                }

            }
    };
}
signed main()
{
    fastio;
    Problem::Program program=Problem::Program();
    return 0;
}