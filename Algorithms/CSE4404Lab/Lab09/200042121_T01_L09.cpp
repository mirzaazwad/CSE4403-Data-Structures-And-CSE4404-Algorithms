#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define N 105
using namespace std;
int capacity[N][N];
int n,parents[N];

int bfs(int src,int des)
{
    int vis[110]= {0};
    vis[src]=1;
    parents[src]=-1;
    queue<int>Q;
    Q.push(src);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=1; i<=n; i++)
        {
            if(vis[i] or capacity[u][i]<=0) continue;
            Q.push(i);
            vis[i]=1;
            parents[i]=u;

        }
    }

    return vis[des];
}
int maxFlow(int src,int des)
{
    int f=0;
    while(bfs(src,des))
    {

        int path=1e9;
        for(int i=des; i!=src; i=parents[i]) path=min(path,capacity[parents[i]][i]);

        for(int i=des; i!=src; i=parents[i])
        {

            int u=parents[i];
            int v=i;

            capacity[u][v]-=path;
            capacity[v][u]+=path;
        }

        f+=path;

    }
    return f;
}



int main()
{
    int test,cs=0;
    cin>>test;
    while(test--)
    {
        memset(capacity,0,sizeof(capacity));


        int m,s,t;
        cin>>n>>s>>t>>m;

        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            capacity[a][b]+=c;
            capacity[b][a]+=c;
        }
        cout <<"Case "<<++cs<<": "<< maxFlow(s,t) << "\n";

    }


}
