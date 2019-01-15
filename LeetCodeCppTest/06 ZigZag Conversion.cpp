/*
*find the relation between line-reading and index in s
*2018.12.27
*Liu
*/
class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int num=s.length();
        int k=2*numRows-2;//nums in every circle
        if(numRows==1)//k==0
            return s;
        
        //1 line
        int cur=0;//index in s
        while(cur<num){
            res.append(1,s[cur]);
            cur+=k;
        }
        //2 to r-1 line
        int i=1;
        for(;i<numRows-1;++i){//line i+1
            cur=i;//start
            while(cur<num){
                res.append(1,s[cur]);
                cur=cur+k-2*i;
                if(cur<num)
                    res.append(1,s[cur]);
                cur=cur+2*i;
            }
        }
        //r line
        cur=numRows-1;
        while(cur<num){
            res.append(1,s[cur]);
            cur+=k;
        }
        return res;
    }
};
