/*
 *2018.12.31
 *Liu
 */
//ok,@kun3,O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> cur(3);
        int target=0,l=0,r=0,sum23=0;
        for(int i=0;i<nums.size();++i){//1:nums[i]
            target=-nums[i];
            l=i+1;
            r=nums.size()-1;
            while(l<r){//2,3:(i+1)..(nums.size()-1)
                sum23=nums[l]+nums[r];
                if(sum23<target)
                    l++;
                else if(sum23>target)
                    r--;
                else{
					cur[0] = nums[i];
					cur[1] = nums[l];
					cur[2] = nums[r];
					ans.push_back(cur);
					while (l < r&&nums[l] == cur[1])++l;//same left val
					while (l < r&&nums[r] == cur[2])--r;//same right val
				}
            }
            while(i+1<nums.size()&&nums[i+1]==nums[i])++i;//same first val
        }
        return ans;
    }
};


//Time Limit Exceeded O(n^3)
class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur(3);
        while(nums.size()>=3){
            //cur[0]=nums[0];
            for(int i=1,j=2;i<nums.size()-1;++i){
                //cur[1]=nums[i];
                for(j=i+1;j<nums.size();++j){
                    if(nums[0]+nums[i]+nums[j]==0){
                        cur[0]=nums[0];
                        cur[1]=nums[i];
                        cur[2]=nums[j];
                        sort(cur.begin(),cur.end());
                        if(find(ans.begin(),ans.end(),cur)==ans.end())
                            ans.push_back(cur);
                        break;//next i
                    }
                }
            }
            nums.erase(nums.begin());
        }
        return ans;
    }
};

//Time Limit Exceeded O(n^2)
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> cur(3);
        int s12=0,p3=0;
        int p=0;
        while(p<nums.size()&&nums[p]<=0)++p;//p is the number>0 orp==nums.size() 
        for(int i=0,j=1;i<p;++i){//1:nums[i]
            for(j=i+1;j<nums.size()-1;++j){//2:nums[j]
                s12=nums[i]+nums[j];
                if(s12>0)
                    break;//next i
                else if(s12==0){
                    if(p-1>j&&nums[p-1]==0)//3:0
                    {
                        cur[0]=nums[i];
                        cur[1]=nums[j];
                        cur[2]=0;
                        ans.push_back(cur);
                    }
                }
                else{//s12<0
                    p3=max(p,j+1);//num3's index >=p&&>j
                    if(find(nums.begin()+p3,nums.end(),-s12)!=nums.end()){
                        cur[0]=nums[i];
                        cur[1]=nums[j];
                        cur[2]=-s12;
                        ans.push_back(cur);
                    }
                    /*while(p3<nums.size()){
                        if(s12+nums[p3]==0){
                            cur[0]=nums[i];
                            cur[1]=nums[j];
                            cur[2]=nums[p3];
                            ans.push_back(cur);
                            break;
                        }
                        if(s12+nums[p3]>0)
                            break;
                    }*/
                }
                while(j+1<nums.size()&&nums[j+1]==nums[j])++j;//same val
            }
            while(i+1<nums.size()&&nums[i+1]==nums[i])++i;//same val
        }
        return ans;
    }
};
