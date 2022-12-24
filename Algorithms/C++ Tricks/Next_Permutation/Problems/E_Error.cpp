#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define SIZE 200000
#define Min 0
#define Max 99999999
using namespace std;


int main(void){
    int N;
    vector<long long>arr;
    long long sum=0,x;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    do{
        sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
            if(sum<Min || sum>Max){
                break;
            }
        }
        if(sum<Min || sum>Max){
                continue;
        }
        else{
            for(int i=0;i<N;i++)cout<<arr[i]<<endl;
            return 0;
        }
    }while(next_permutation(arr.begin(),arr.end()));
    cout<<"Error"<<endl;


    return 0;
}
