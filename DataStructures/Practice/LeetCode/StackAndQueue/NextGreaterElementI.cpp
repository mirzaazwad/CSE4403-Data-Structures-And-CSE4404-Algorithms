class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        queue<int>s;
        int siz1=nums1.size();
        int siz2=nums2.size();
        for(int i=0;i<siz1;i++){
            for(int j=0;j<siz2;j++){
                if(nums1[i]==nums2[j]){
                    s.push(j);
                }
            }
        }
        vector<int>ans;
        while(!s.empty()){
            int start=s.front();
            bool found=false;
            for(int j=start+1;j<siz2;j++){
                if(nums2[j]>nums2[start]){
                    ans.push_back(nums2[j]);
                    found=true;
                    break;
                }
            }
            if(!found){
                ans.push_back(-1);
            }
            s.pop();
        }
        return ans;
    }
};
