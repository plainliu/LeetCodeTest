/**
 *2019.01.04
 *Liu
 *
 */
 
//4 ms,99.01%
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0)return 0;
        int len=nums.size();
        for(int i=0;i<len-1;++i){
            if(nums[i]==val){
                nums[i]=nums[len-1];
                len--;
                i--;
            }
        }
        if(nums[len-1]==val)
            len--;
        return len;
    }
};
