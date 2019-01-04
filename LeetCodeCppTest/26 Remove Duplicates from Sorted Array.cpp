/**
 *
 *2019.01.04
 *Liu
 */
 
//using iterator
//48 ms,10.76% 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1)return nums.size();
        vector<int>::iterator it;
        for(it=nums.begin()+1;it!=nums.end();){
            if(*it==*(it-1))
                it=nums.erase(it);
            else
                ++it;
        }
        return nums.size();
    }
};

//28 ms,59.88%
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int i=0;
        for(int j=1;j<nums.size();++j){
            if(nums[j]!=nums[i]){//nums[i] not need extra compute,so fast than "nums[j]!=nums[j-1]"
                ++i;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};
