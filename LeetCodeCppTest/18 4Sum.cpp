/*
 *2019.01.02
 *Liu
 */
//same algorithm as 3Sum Problem
//28 ms, 59.91%
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4)return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> cur(4);//size=4
        int goal=0,l=0,r=0,sumlr=0;
        for(int i=0,j=0;i<nums.size()-3;++i){
            cur[0] = nums[i];//a
            for(j=i+1;j<nums.size()-2;++j){
                cur[1] = nums[j];//b
                goal=target-nums[i]-nums[j];
                l=j+1;
                r=nums.size()-1;
                while(l<r){//2,3:(i+1)..(nums.size()-1)
                    sumlr=nums[l]+nums[r];
                    if(sumlr<goal)
                        l++;
                    else if(sumlr>goal)
                        r--;
                    else{
                        cur[2] = nums[l];//c
                        cur[3] = nums[r];//d
                        ans.push_back(cur);
                        while (l < r&&nums[l] == cur[2])++l;//same left val
                        while (l < r&&nums[r] == cur[3])--r;//same right val
                    }
                }
                while(j+1<nums.size()&&nums[j+1]==nums[j])++j;//same 2nd val
            }
            while(i+1<nums.size()&&nums[i+1]==nums[i])++i;//same 1st val
        }      
        return ans;
    }
};
