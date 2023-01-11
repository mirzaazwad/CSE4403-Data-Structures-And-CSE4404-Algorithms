/*
*Author: Mirza Mohammad Azwad
*Institude: Islamic University of Technology
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
using namespace std;
 
#define ll long long
#define endl "\n"
 

void solve(){
    ll S;
    cin>>S;
    ll root=(ll)ceil(sqrt(S));
    ll lackings=root*root-S;
    ll row,column;
    //first we assume that root is odd
    //notice that the pattern increases similar to how the upper side and the rightmost side of a square increases
    //so essentially if the lackings>=root the expected row becomes the column and vice versa
    //this is how the pattern changes
    if(lackings<root){
        row=root;
        column=lackings+1;//essentially the row is basically the difference between the square number and the actual seconds
    }
    else{
        column=root;
        //now note that if the lackings>root we cannot directly determine using our initial root
        //the best way to find the height or the row becomes subtracting it from previous root instead of the next root, say for 17, 16 instead of 25
        row=S-(root-1)*(root-1);
    }
    //we assumed that root was odd
    if(root%2==0){
        swap(row,column);
    }
    cout<<column<<" "<<row<<endl;//you have to print based on a coordinate system x followed by y, y indicates row and x indicates column
    

    

    
}
int main()
{
    fastio;
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
