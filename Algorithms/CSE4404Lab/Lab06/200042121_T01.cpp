#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;
int n,k,expect;
vector<int>nums;
int getSum(int mask){
  int sum=0;
  for(int i=0;i<n;i++){
    if(mask&(1<<i)){
      sum+=nums[i];
    }
  }
  return sum;
}

bool isParitionable(int mask){
  int sum=getSum(mask);
  if(mask==((1<<n)-1)){
    return true;
  }
  bool ret=false;
  int required=sum/expect;
  for(int i=0;i<n;i++){
    if(mask&(1<<i))continue;
    if(getSum(mask|(1<<i))<=(required+1)*expect){
      ret=ret||isParitionable(mask|(1<<i));
    }
  }
  return ret;
}



int main()
{
    fastio;
    cin>>n>>k;
    expect=0;
    for(int i=0;i<n;i++){
      int x;
      cin>>x;
      nums.push_back(x);
      expect+=x;
    }
    expect/=k;
    if(isParitionable(0)){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }

    return 0;
}