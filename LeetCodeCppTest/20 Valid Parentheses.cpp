/*
 *2019.01.02
 *Liu
 */

//4 ms,41.95% 
class Solution {
public:
    bool isValid(string s) {
        stack<char> ch;
        while(!s.empty()){
            if(s[0]==')'||s[0]==']'||s[0]=='}'){//if match with top of ch
                if(ch.empty())return false;
                if((s[0]==')'&&ch.top()=='(')
                  ||(s[0]==']'&&ch.top()=='[')
                  ||(s[0]=='}'&&ch.top()=='{'))
                    ch.pop();//match
                else
                    return false;
            }
            else
                ch.push(s[0]);
            s.erase(s.begin());
        }
        if(ch.empty())
            return true;
        return false;
    }
};
