#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class Solution
{
public:
  set<pair<int, int>> s;
  int cnt = 0;
  int binSearch(int l, int r, long long key, vector<int> &nums)
  {
    int lo = l;
    int hi = r;
    while (lo <= hi)
    {
      int mid = (lo + hi) / 2;

      if ((long long)nums[mid] >= key)
        hi = mid - 1;
      else if ((long long)nums[mid] < key)
        lo = mid + 1;
    }
    return lo;
  }

  void call(int l, int r, vector<int> &nums)
  {
    int mid = (l + r) / 2;
    if (l < r)
    {

      call(l, mid, nums);
      call(mid + 1, r, nums);
    }
    int ix = binSearch(mid+1, r, (long long)nums[l]/2, nums);
    if((long long)nums[ix]>2*(long long)nums[l]){
      s.emplace(ix,l);
    }
  }
  int reversePairs(vector<int> &nums)
  {
    call(0, nums.size() - 1, nums);
    return s.size();
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