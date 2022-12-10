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
            vector<string>sentence;
            string target;
            const int mod=1e9+7;
            map<int,vector<string>>mp;
        public:
            Program(int t=1){
                for(int i=1;i<=t;i++){
                    takeInput();
                    solve();
                    clearSpace();
                }
            }
 
            void takeInput(){
                string s;
                while(cin>>s){
                    sentence.push_back(s);
                }
                target=sentence.back();
                sentence.pop_back();
            }

            int get_hash(string word){
                set<int>s;
                for(char c:word){
                    s.insert(tolower(c)-'a');
                }
                int sum=0;
                int base=31;
                for(auto u:s){
                    sum=(sum*31+u)%mod;
                }
                return sum;
            }
 
            void clearSpace(){
                sentence.clear();
                target.clear();
            }
            void solve(){
                for(string s:sentence){
                    mp[get_hash(s)].push_back(s);
                }
                vector<string>ans=mp[get_hash(target)];
                int len=ans.size();
                for(int i=0;i<len-1;i++){
                    cout<<ans[i]<<", ";
                }
                cout<<ans.back()<<endl;
            }
    };
}
signed main()
{
    fastio;
    Problem::Program program=Problem::Program();
    return 0;
}
