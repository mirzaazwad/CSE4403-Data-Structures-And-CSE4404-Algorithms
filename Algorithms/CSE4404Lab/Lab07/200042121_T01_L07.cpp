#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class Solution
{
private:
  int cnt;
public:
  void merge(int l,int mid,int r,vector<int>& nums){
    int i=l;
    int j=mid+1;
    while(i<=mid){
      while(j<=r && nums[i]>2*(long long)nums[j]){
        j++;
      }
      i++;
      cnt+=(j-(mid+1));
    }
    sort(nums.begin()+l,nums.begin()+r+1);
  }

  void merge_sort(int l,int r,vector<int>& nums){
    if(l<r){
      int mid=(l+r)/2;
      merge_sort(l,mid,nums);
      merge_sort(mid+1,r,nums);
      merge(l,mid,r,nums);
    }
  }

  int reversePairs(vector<int> &nums)
  {
    cnt=0;
    merge_sort(0, nums.size()-1, nums);
    return cnt;
  }
};

int main(void)
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int &i : arr)
  {
    cin >> i;
  }
  Solution *solve = new Solution();
  cout << solve->reversePairs(arr) << endl;
  ;
}