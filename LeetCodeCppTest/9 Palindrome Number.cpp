/*
 *leetcode 9
 *Liu
 *2018.12.28
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int len=0;
        int a[10]={0};//INT_MAX 10charactors
        while(x!=0){//put x's every into a[]
            a[len++]=x%10;
            x=x/10;
        }
        for(int i=0,j=len-1;i<j;++i,--j)//a[0..len-1]
            if(a[i]!=a[j])return false;
        return true;
    }
};
