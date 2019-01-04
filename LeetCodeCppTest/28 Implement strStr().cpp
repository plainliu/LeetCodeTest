/**
 *2019.01.04
 *Liu
 *
 */
 
//652 ms,10.10%
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        int i=0,j=0,k=0;
        while(i<haystack.size()&&j<needle.size()){
            k=i;
            while(i<haystack.size()&&j<needle.size()&&haystack[i]==needle[j])
                {++i;++j;}
            if(j==needle.size())
                return k;
            j=0;i=k+1;
        }
        return -1;
    }
};

//4 ms,98.94%
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        int i=0,j=0;
        while(i<haystack.size()){
            if(haystack[i]==needle[j])
                j++;
            else
                {i=i-j;j=0;}//move
            if(j==needle.size())
                return i-j+1;
            ++i;
        }
        return -1;
    }
};
