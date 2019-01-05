/**
 *2019.01.04
 *Liu
 *
 */

//12 ms,3.19% 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0)return 0;
        int l=0,r=nums.size()-1,m=0;
        if(target<=nums[l])return 0;
        if(target>nums[r])return nums.size();
        while(l<r){
            if(r-l==1)return r;
            m=(l+r)/2;
            if(target==nums[m])
                return m;
            if(target<nums[m])
                r=m;
            else if(target>nums[m])
                l=m;
        }
        return r;
    }
};
