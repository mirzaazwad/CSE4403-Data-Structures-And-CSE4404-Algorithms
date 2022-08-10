#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int binarySearch(vector<int>v, int n){
    int start=0;
    int end=v.size();
    while(end-start>1){
        int mid=(start+end)/2;
        if(v[mid]==n)return mid;
        else if(n>v[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int binarySearchRecursive(vector<int> v,int n,int start, int end){
    if(start>end){
        return -1;
    }
    else{
        int mid=(start+end)/2;
        if(v[mid]==n)return mid;
        else if(n>v[mid]){
            return binarySearchRecursive(v,n,mid+1,end);
        }
        else{
            return binarySearchRecursive(v,n,start,mid-1);
        }

    }
}

int main()
{
    fastio;
    int x;
    vector<int>v;
    while(cin>>x,x!=-1){
        v.push_back(x);
    }
    int val;
    cin>>val;
    cout<<binarySearch(v,val)<<endl;


    return 0;
}
