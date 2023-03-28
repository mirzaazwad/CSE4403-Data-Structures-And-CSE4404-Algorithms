#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class Solution
{
private:
  long long low;
  long long high;
public:
  int merge_sum(vector<long long>& prefix, int l, int r){
    if(l == r){
        return prefix[l] >= low && prefix[r] <= high;
    }
    int cnt = 0;
    int mid = (l+r)>>1;
    int lSum = merge_sum(prefix, l, mid);
    int rSum = merge_sum(prefix, mid+1, r);
    int i = l;
    while(i <= mid){
        cnt+=(upper_bound(prefix.begin()+mid+1,prefix.begin()+r+1,prefix[i]+high)-lower_bound(prefix.begin()+mid+1,prefix.begin()+r+1,prefix[i]+low));
        i++;
    }
    sort(prefix.begin()+l,prefix.begin()+r+1);
    return lSum+rSum+cnt;
}

  int countRangeSum(vector<int>& nums, int lower, int upper) {
        low=lower;
        high=upper;
        int n=nums.size();
        vector<long long>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
          prefix[i]=prefix[i-1]+nums[i];
        }
        return merge_sum(prefix,0,n-1);
  }
};

int main(void)
{
  int n;
  cin >> n;
  int low,upper;
  cin>>low>>upper;
  vector<int> arr(n);
  for (int &i : arr)
  {
    cin >> i;
  }
  Solution *solve = new Solution();
  cout<<solve->countRangeSum(arr,low,upper);
}