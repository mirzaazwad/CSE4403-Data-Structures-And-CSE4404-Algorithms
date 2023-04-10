#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define N 225
using namespace std;
int capacity[N][N];
int parents[N];
int n;

int bfs(int src,int des)
{
    int vis[225]= {0};
    vis[src]=1;
    parents[src]=-1;
    queue<int>Q;
    Q.push(src);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0; i<=2*n+1; i++)
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
        cin>>n;
        vector<int>regulator(n+1);
        for(int i=1;i<=n;i++){
          cin>>regulator[i];
        }
        memset(capacity,0,sizeof(capacity));
        memset(parents,-1,sizeof(parents));
        int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            capacity[a][n+b]=c;
            capacity[n+b][b]=regulator[b];
        }
        int s,t;
        cin>>s>>t;
        vector<int>barisal(s),dhaka(t);
        for(int &i:barisal)cin>>i;
        for(int &i:dhaka)cin>>i;
        for(int i:barisal){
          capacity[0][i+n]=1e9;
          capacity[i+n][i]=regulator[i];
        }
        for(int i:dhaka){
          capacity[i][2*n+1]=1e9;
        }
        cout <<"Case "<<++cs<<": "<< maxFlow(0,2*n+1) << "\n";
    }


}