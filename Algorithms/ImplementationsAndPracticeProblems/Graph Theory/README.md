# Graph Theory
Graph theory is one of the most essential parts of competitive programming contests and such, basically it deals with various types of graphs as defined mathematically(Discrete Mathematics)
in a way such that these graphs consists of edges that join one node to another. Nodes are essentially like leaves on a tree with the edges being joining them.
Graphs are a good starting point for understanding other data structures such as different forms of trees. A node is also often called a vertex. 
So there are many different ways to represent graphs as discussed here:
1) [Graph Theory MIT Playlist](https://www.youtube.com/playlist?list=PL6MpDZWD2gTF3mz26HSufmsIO-COKKb5j)
2) [Graph Theory from a Computer Science Perspective](https://youtu.be/LFKZLXVO-Dg)
3) [Detailed Mathematical Understanding of Graph Theory and other Discrete Mathematics Topics](https://www.youtube.com/playlist?list=PLDDGPdw7e6Aj0amDsYInT_8p6xTSTGEi2)
4) Understanding of [recursion](https://youtu.be/ngCos392W4w) A fundamental part of understanding the intricacy of graph theory with respect to competitive programming.

Let's first take a graph:

![Graph Image](https://github.com/mirzaazwad/Competitive-Programming/blob/main/Category-Wise%20Problems/Graph%20Theory/Implementations/Example%20Graph.png)

This graph consists of **nodes** represented by numbers and the connection between these nodes is represented by lines called **edges**.

**Nodes** are also known as **vertices**.

The **length** of the path is defined as the number of **edges** in it. 

n is used traditionally to define the number of nodes and m is used traditionally to define the number of edges.

## Path, Connectivity and Cycles

A **Path** is a **Cycle** if the first and last nodes are the same. A **Path** is a **Simple** Path if each node appears at most once in the path.

A Graph is said to be **connected** if there exists a path between any 2 nodes.

The connected parts of graph are called its **components**.

See illustrations of these ideas in Competitive Programming Handbook in the introduction README.md of this repository.[Click Here](https://drive.google.com/file/d/1lWrMyp3bNgAebbpVaeOnHOBhjM1HU_JZ/view?usp=sharing)

## Direction of Graphs

A graph is said to be **directed** if the graph can be traversed in one direction only. 

## Weighted Graphs

In a **weighted graph** each edge is assigned a **weight**. The weights are often interpreted as **edge lengths**.

Weighted graphs also address the idea of the shortest path between 2 nodes. 

## Neighbours and Degrees

Two nodes are **neighbors** or **adjacent** if there is an **edge** between them. The
**degree** of a node is the number of its neighbors.

## Coloring of a Graph

In a **coloring** of a graph, each node is assigned a color so that no adjacent nodes
have the same color.
A graph is **bipartite** if it is possible to color it using two colors. It turns out
that a graph is bipartite exactly when **it __does not__ contain a cycle with an odd
number of edges.**


## Representing Graphs Algorithimically


```CPP
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> edges;//Edge List
int adjMat[102][102];//Adjacency Matrix
vector<int> adjL[102];//Adjacency List

vector<pair<int, pair<int, int>>> edges2;//Weighted Edge List
vector<pair<int, int>> adjL2[102];//Weighted Adjacency List

int main()
{
    int i, a, b, w;
    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cin >> a >> b;
        edges.push_back({min(a, b), max(a, b)});

        adjMat[a][b] = 1;
        adjMat[b][a] = 1;

        adjL[a].push_back(b);
        adjL[b].push_back(a);

        cin >> w;
        edges2.push_back({w, {a, b}});

        adjMat[a][b] = w;
        adjMat[b][a] = w;

        adjL2[a].push_back({w, b});
        adjL2[b].push_back({w, a});
    }
}
```

## DFS Implementation

Representing DFS Algorithimically

###### Method 1:
```CPP
#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)

#define endl "\n"

using namespace std;

bool vis[12];
vector<int>v[12];
vector<int>parent(12,-1);

void dfs(int node,int par){
    vis[node]=true;
    parent[node]=par;
    for(auto u:v[node]){
        if(!vis[u]){
            dfs(u,node);
        }
    }
}

int main()
{
    fastio;
    int a,b;
    for(int i=0;i<9;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(6,0);
    for(int i=0;i<12;i++){
        cout<<i<<" "<<parent[i]<<"\n";
    }
    return 0;
}
```
DFS stands for Depth-First Search, in this case, we traverse the graph or tree from the root node to the tip of another branch before moving on to the next branch. Essentially we keep following edges, going deeper and deeper into the graph, when we reach a node that has no edges to any other nodes, we go back to the previous node and continue the process. Here I implemented it using recursion(Method 1), as recursion can be used as a replacement for stack, instead of recursion a more theoretical approach would be to use a stack(Method 2) to keep track of the exploration track, pushing a node when we explore it and popping a node when we go back. The backtracking strategy explores solutions this way. The recursion approach is more suitable for Competitive Programming.
For better understanding check the dfs vs bfs comparison at the start of the **DFS vs BFS** section

###### Method 2:

```CPP
#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)

#define endl "\n"

using namespace std;

bool vis[12];
vector<int>v[12];
vector<int>parent(12,-1);
stack<int>s;

void dfs(int node,int par){
    vis[node]=true;
    parent[node]=par;
    s.push(node);
    while(!s.empty()){
        node=s.top();
        s.pop();
        for(auto u:v[node]){
            if(!vis[u]){
                parent[u]=node;
                s.push(u);
                vis[u]=true;
            }
        }
        
    }  
}

int main()
{
    fastio;
    int a,b;
    for(int i=0;i<9;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(6,0);
    for(int i=0;i<12;i++){
        cout<<i<<" "<<parent[i]<<"\n";
    }
    return 0;
}
```

## BFS Implementation

```CPP
#include<bits/stdc++.h>
using namespace std;


bool vis[12]={false};
vector<int>v[12];
vector<int>dis(12,-1);
queue<int>q;

void bfs(int node){
    q.push(node);
    vis[node]=true;
    dis[node]=0;
    while(!q.empty()){
        node=q.front();
        q.pop();
        for(auto u:v[node]){
            if(!vis[u]){
                q.push(u);
                vis[u]=true;
                dis[u]=dis[node]+1;
            }
        }
    }
}
int main(){

    int a,b;
    for(int i=0;i<9;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(6);
    for(int i=0;i<12;i++){
        cout<<i<<" "<<dis[i]<<"\n";
    }
}
```

BFS stands for Breadth First Search, here it explores the neighbouring nodes, level by level before going deeper into the graph. Essentially, it explores graph as per level: first the neigbours of your start node, then its neighbours' neighbours and so on and so forth. To keep track of the nodes we visit, we use a queue. Once we explore a node, we enqueue its children and then dequeue the next node to explore. For better understanding check the dfs vs bfs comparison at the start of the **DFS vs BFS** section

## DFS vs BFS

![DFS vs BFS](https://github.com/mirzaazwad/Competitive-Programming/blob/main/Category-Wise%20Problems/Graph%20Theory/Implementations/DFS%20vs%20BFS.png)
The Image is from the book Computer Science Distilled by Wladston Ferreira Filho

We notice that bfs and dfs only differ in their use of stacks or queues but how do we understand which one best suits our cause. The DFS approach is simpler to implement and consumes less memory as you only need to store the parent nodes leading to the current node. While in BFS, you have to store the entire frontier of the search process. If you have a graph of millions of nodes, it would not be practical. When you suspect that the node you are searching isn't many levels away from the start, it's usually worth paying the higher cost of bfs, because you are likely to find the node faster. When you need to explore all the nodes of a graph its usually bettter to go for dfs for its simpler implementation and smaller memory footprint.

Understanding the concepts of DFS and BFS: [Click Here](https://youtu.be/pcKY4hjDrxk)

Understanding the concepts of How Recursion Can be Used in a similar way to stack: [Click Here](https://youtu.be/ygK0YON10sQ)

Visualising Graphs and Graph traversals. [Click Here](https://csacademy.com/app/graph_editor/)




