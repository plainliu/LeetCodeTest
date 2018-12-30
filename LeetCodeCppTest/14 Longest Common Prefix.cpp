/*
 *2018.12.30
 *Liu
 */
//Approach 1: Horizontal scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num=strs.size();
        if(num==0)return "";
        string ans=strs[0];//start from strs[0]
        for(int i=1,len=0,j=0;i<num;++i){//campare to strs[1..num-1],ans=longest commom str(ans,strs[i])
            len=min(ans.length(),strs[i].length());
            for(j=0;j<len;++j){
                if(ans[j]!=strs[i][j])
                    break;
            }
            if(j==0)return "";
            if(j<ans.length())
                ans.erase(j);
        }
        return ans;
    }
};

//Approach 2: Vertical scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num=strs.size();
        if(num==0)return "";
        for(int i=0;i<strs[0].length();++i){
            char c=strs[0][i];
            for(int j=1;j<strs.size();++j){
                if(strs[j].length()==i||strs[j][i]!=c)
                    return strs[0].substr(0,i);//from 0,n char
            }
        }
        return strs[0];
    }
};

//Approach 3: Divide and conquer
class Solution {
public:
    string Cmp(string&s1,string&s2){
        int i=0;
        for(;i<s1.length();++i){
            if(s2.length()==i||s1[i]!=s2[i])
                return s1.substr(0,i);
        }
        return s1;
    }
    string lgstCP(vector<string>& strs,int l,int r){
        if(l==r)return strs[l];//1
        if(r-l==1)return Cmp(strs[l],strs[r]);//2
        string s1=lgstCP(strs,l,(l+r)/2);
        string s2=lgstCP(strs,(l+r)/2+1,r);
        return Cmp(s1,s2);
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";
        return lgstCP(strs,0,strs.size()-1);
    }
};
