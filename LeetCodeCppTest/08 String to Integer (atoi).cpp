/*
 *leetcode 8
 *Liu
 *2018.12.28
 */

class Solution {
public:
    int myAtoi(string str) {
        int len=str.length();
        int flag=1;
        int res=0;//the result
        int i=0;
        while(i<len&&str[i]==' ')
            i++;
        if(i<len){//i==len:contains only whitespace characters
            if(str[i]=='-'){flag=-1;++i;}
            else if(str[i]=='+')++i;
            while(i<len){
                if(str[i]>=48 && str[i]<=57){//0-9
                    if(flag*res>(INT_MAX-str[i]+48)/10)
                        return INT_MAX;
                    if(flag*res<(INT_MIN+str[i]-48)/10)
                        return INT_MIN;                        
                    res=res*10+str[i++]-48;
                }
                else
                    break;
            }
        }
        return res*flag;
    }
};
