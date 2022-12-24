#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int lis(int *input,int n){
    int output[n];
    for(int i=0;i<n;i++){
        output[i]=1;
        for(int j=i-1;j>=0;j--){
            if(input[j]>input[i])continue;
            output[i]=max(output[i],output[j]+1);
        }
    }
    int best=0;
    for(int i=0;i<n;i++){
        best=max(output[i],best);
    }
    return best;
}

int main()
{
    fastio;
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    cout<<lis(input,n)<<endl;
    return 0;
}