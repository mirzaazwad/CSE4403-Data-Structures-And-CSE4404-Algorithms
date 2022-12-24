//this problem is from codeforces gym, the reason lower_bound is being used over a traditional linear search is the time constraint, now we know that linear search
//has a time complexity of O(N) but lower_bound is in a way similar to binary_search and hence it has complexity of O(logN), to read more about lower_bound refer to the
//articles given in the lower_bound(C++) section of this repo. Also the link to the problem, link: https://codeforces.com/gym/101807/problem/H
#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"

using namespace std;


int main(void){
    fastio;
    int N;
    cin>>N;
    vector<long long>D(N+1);
    for(int i=1;i<=N;i++)cin>>D[i];
    int Q;
    cin>>Q;
    while(Q--){
        int X,Y;cin>>X>>Y;
        int ix;
        ix=lower_bound(D.begin(),D.end(),Y-X)-D.begin();
        if(D[ix]!=Y-X)if(Y-D[ix]<=0||ix>N||abs(D[ix]-(Y-X))>=abs(D[ix-1]-(Y-X)))ix--;
        cout<<ix<<endl;
    }


    return 0;
}
