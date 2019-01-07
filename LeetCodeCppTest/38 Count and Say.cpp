/**
 *2019.01.07
 *Liu
 */

//4 ms,52.14%
class Solution {
public:
    string aly(string str){
        string res;
        int count=1,num=str[0];
        str.erase(str.begin());
        while(str.size()>0){
            if(str[0]==num){
                ++count;
                str.erase(str.begin());
            }
            else{
                res.push_back(count+48);
                res.push_back(num);
                count=1;
                num=str[0];
                str.erase(str.begin());
            }
        }
        res.push_back(count+48);
        res.push_back(num);
        return res;
    }
    string countAndSay(int n) {
        string pre,cur="1";
        int cn=1;
        while(cn<n){
            pre=cur;
            cur=aly(pre);
            cn++;
        }
        return cur;
    }
};
