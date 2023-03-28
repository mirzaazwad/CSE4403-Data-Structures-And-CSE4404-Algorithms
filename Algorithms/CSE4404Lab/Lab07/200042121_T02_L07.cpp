#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge_count(int l, int r, vector<int> &nums, vector<int> &cnt)
    {
        if (l < r)
        {
            int mid = (l + r)>>1;
            merge_count(mid + 1, r, nums, cnt);
            for (int k = l; k <= mid; k++)
            {
                cnt[k] += lower_bound(nums.begin() + mid + 1, nums.begin() + r + 1, nums[k]) - (nums.begin() + mid + 1);
            }
            merge_count(l, mid, nums, cnt);
            sort(nums.begin() + l, nums.begin() + r + 1);
        }
    }
    vector<int> countSmaller(vector<int> &nums)
    {

        vector<int> cnt(nums.size(), 0);
        merge_count(0, nums.size() - 1, nums, cnt);
        return cnt;
    }
};