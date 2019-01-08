/**
 *2018.01.08
 *Liu
 */
 
//swap,let nums[num-1]=num
//4 ms, 89.80%
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(auto &num:nums){
            if(num<=0||num>nums.size())
                num=0;
        }
        for(int i=0;i<nums.size();++i){
            while(nums[i]>0&&nums[nums[i]-1]!=nums[i])
                swap(nums[nums[i]-1],nums[i]);
        }
        for(int i=0;i<nums.size();++i)
            if(nums[i]!=i+1)
                return i+1;
        return nums.size()+1;
    }
};

//if 0<num<=nums.size(),set nums[num-1] minus
//it has two effects,position i being minus mean num i+1 exists in nums;
//meanwhile, remain the value of nums[i],while the solution above need to swap several times
//4 ms,89.80%
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(auto &num:nums){
            if(num<=0||num>nums.size())
                num=INT_MAX;
        }
        for(int i=0;i<nums.size();++i){
            if(abs(nums[i])<INT_MAX&&nums[abs(nums[i])-1]>0)
                nums[abs(nums[i])-1]*=-1;
        }
        for(int i=0;i<nums.size();++i)
            if(nums[i]>0)
                return i+1;
        return nums.size()+1;
    }
};
