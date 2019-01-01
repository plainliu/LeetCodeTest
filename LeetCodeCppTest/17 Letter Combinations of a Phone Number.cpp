/*
 *2018.01.01
 *Liu
 */
//4ms,5%
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //'2'index:('2'-48)-2='2'-50
        char ch[8][4]={{'a','b','c'},{'d','e','f'},
                       {'g','h','i'},{'j','k','l'},{'m','n','o'},
                       {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        vector<string> ans;
        string p;
        for(int i=0,j=0,ans_size=0;i<digits.size();++i){
            ans_size=ans.size();
            for(j=0;ans.size()==0||j<ans_size;++j){//j:index on ans,elems in ans add 3char
                if(ans.size()==0)
                    p="";
                else
                    p=ans[j];
                //abc or wxyz,add to ans
                p.append(1,ch[digits[i]-50][0]);
                ans.push_back(p);
                p[i]=ch[digits[i]-50][1];
                ans.push_back(p);
                p[i]=ch[digits[i]-50][2];
                ans.push_back(p);
                if(digits[i]-48==7||digits[i]-48==9){
                    p[i]=ch[digits[i]-50][3];
                    ans.push_back(p);
                }
            }
            //delete old elems
            ans.erase(ans.begin(),ans.begin()+ans_size);
        }
        return ans;
    }
};

//2:using queue,4ms,5%
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};
        //'2'index:('2'-48)-2='2'-50
        char ch[8][4]={{'a','b','c'},{'d','e','f'},
                       {'g','h','i'},{'j','k','l'},{'m','n','o'},
                       {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        vector<string> ans;
        queue<string> q;//like BFS of binary tree
        string p;
        int s=(digits[0]=='7'||digits[0]=='9')?4:3;
        p.append(1,ch[digits[0]-50][0]);q.push(p);
        for(int m=1;m<s;++m){p[0]=ch[digits[0]-50][m];q.push(p);}
        
        int i=1;
        while(q.front().size()<digits.size()){//untill q is ans
            q.front().append(1,'!');//length+1
            p=q.front();
            i=q.front().size()-1;
            s=(digits[i]=='7'||digits[i]=='9')?4:3;
            for(int m=0;m<s;++m){p[i]=ch[digits[i]-50][m];q.push(p);}
            
            q.pop();
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
