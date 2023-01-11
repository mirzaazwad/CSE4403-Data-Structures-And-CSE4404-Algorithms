#include<bits/stdc++.h>
using namespace std;

int vis[8][8];
int fx[]={2,2,-2,-2,1,-1,1,-1};
int fy[]={1,-1,1,-1,2,2,-2,-2};
int row=8;
int col=8;
int d[8][8];

void bfs(int sx,int sy) 
{
	memset(vis,0,sizeof vis);
	vis[sx][sy]=1;
	queue<pair<int,int>>q; 
	q.push(pair<int,int>(sx,sy));
	while(!q.empty())
	{		
		int x = q.front().first; 
             int y = q.front().second;
             q.pop();
		for(int k=0;k<8;k++)
		{
			int tx = x + fx[k];
			int ty = y + fy[k];
			if(tx>=0 and tx<row and ty>=0 and ty<col and vis[tx][ty]==0)
			{				
				vis[tx][ty]=1;
				d[tx][ty]=d[x][y] + 1; 
				q.push(pair<int,int>(tx,ty)); 
			}
		}
	}
}

int findPath(int sx,int sy,int ex,int ey){
  if(sx==ex && sy==ey){
    return 0;
  }
  d[sx][sy]=0;
  bfs(sx,sy);
  if(d[ex][ey]!=-1){
    return d[ex][ey];
  }
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(vis[i][j]){
        return findPath(i,j,ex,ey);
      }
    }
  }
  return -1;
}




int main(void){
  string start,end;
  while(cin>>start>>end){
    memset(d,-1,sizeof(d));
    memset(vis,0,sizeof(vis));
    pair<int,int>source,destination;
    source.first=start[0]-'a';
    source.second=start[1]-'1';
    destination.first=end[0]-'a';
    destination.second=end[1]-'1';
    int moves=findPath(source.first,source.second,destination.first,destination.second);
    cout<<"To get from "<<start<<" to "<<end<<" takes "<<moves<<" knight "<<"moves"<<"."<<endl;
  }
}
