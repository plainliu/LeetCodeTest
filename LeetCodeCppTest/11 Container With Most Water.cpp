/*
 *2018.12.29
 *PlainLiu
 */
//Approach 1: Brute Force
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water=0,cur_water=0,num=height.size();
        for(int i=0,j=1;i<num-1;++i){
            for(j=i+1;j<num;++j){
                cur_water=min(height[i],height[j])*(j-i);
                if(cur_water>max_water)max_water=cur_water;
            }
        }
        return max_water;
    }
};

//Approach 2: Two Pointer Approach
class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int max_water=0,num=height.size();
        for(int left=0,right=num-1;left<right;){
            max_water=max(max_water,min(height[left],height[right])*(right-left));
            if(height[left]<height[right])//move point
                left++;
            else
                right--;
        }
        return max_water;
    }
};
