/*
 *2019.01.01
 *Liu
 */
//1：8.18%
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=10000;
        for(int i=0,j=0,k=0;i<nums.size();++i){//1:nums[i]
            for(j=i+1;j<nums.size()-1;++j){
                for(k=j+1;k<nums.size();++k){
                    if(abs(nums[i]+nums[j]+nums[k]-target)<abs(ans-target))
                        ans=nums[i]+nums[j]+nums[k];
                }
                while(j+1<nums.size()&&nums[j+1]==nums[j])++j;//same 2nd val
            }
            while(i+1<nums.size()&&nums[i+1]==nums[i])++i;//same 1st val
        }
        return ans;
    }
};
