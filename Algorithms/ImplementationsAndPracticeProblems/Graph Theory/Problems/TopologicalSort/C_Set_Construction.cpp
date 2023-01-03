// In the name of Allah, The Lord of Mercy, The Giver of Mercy
// Author: Mirza Mohammad Azwad
// Institution: Islamic University of Technology
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ll int64_t
#define short int16_t
#define int int32_t
#define endl "\n"

using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

namespace Problem
{
    class Program
    {
    private:
        vector<int> adj[105];
        int binary[105][105];
        set<int> sets[105];
        vector<int> roots;
        vector<int> in_degree;
        int n;

    public:
        Program(int t = 1)
        {
            for (int i = 1; i <= t; i++)
            {
                clearSpace();
                takeInput();
                solve();
            }
        }

        void takeInput()
        {
            cin.ignore();
            for (int i = 0; i < n; i++)
            {
                string tmp;
                getline(cin, tmp);
                for (int j = 0; j < n; j++)
                {
                    binary[i][j] = tmp[j] - '0';
                    if (binary[i][j])
                    {
                        adj[j+1].push_back(i+1);
                    }
                }
            }
        }

        void clearSpace()
        {
            cin >> n;
            roots.clear();
            memset(binary, 0, sizeof(binary));
            in_degree.assign(n+1, 0);
            for (int i = 0; i < 105; i++)
            {
                adj[i].clear();
                sets[i].clear(); 
            }
        }

        set<int> merge_sets(int u)
        {
            if (sets[u].size())
                return sets[u];
            sets[u].insert(u);
            for (auto v : adj[u])
            {
                set<int> res = merge_sets(v);
                for (auto i : res)
                    sets[u].insert(i);
            }
            return sets[u];
        }

        void solve()
        {
            for (int i = 1; i <= n; i++)
            {
                if (in_degree[i] == 0)
                {
                    roots.push_back(i);
                }
            }
            for (auto i : roots)
            {
                merge_sets(i);
            }
            
            for(int i=1;i<=n;i++){
                cout<<sets[i].size()<<" ";
                for(auto j:sets[i]){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
    };
}
signed main()
{
    fastio;
    int tc;
    cin >> tc;
    Problem::Program program = Problem::Program(tc);
    return 0;
}