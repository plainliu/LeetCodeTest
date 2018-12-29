/*
 *2018.12.29
 *Liu
 */
//Approach 1: naive way,104ms
class Solution {
public:
    int romanToInt(string s) {
        int ans=0,len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='M')
                ans+=1000;
            else if(s[i]=='C'){
                if(i+1<len&&s[i+1]=='M')
                {ans+=900;++i;}
                else if(i+1<len&&s[i+1]=='D')
                {ans+=400;++i;}
                else
                    ans+=100;
            }
            else if(s[i]=='X'){
                if(i+1<len&&s[i+1]=='C')
                {ans+=90;++i;}
                else if(i+1<len&&s[i+1]=='L')
                {ans+=40;++i;}
                else
                    ans+=10;
            }
            else if(s[i]=='I'){
                if(i+1<len&&s[i+1]=='X')
                {ans+=9;++i;}
                else if(i+1<len&&s[i+1]=='V')
                {ans+=4;++i;}
                else
                    ans+=1;
            }
            else if(s[i]=='D')
                ans+=500;
            else if(s[i]=='L')
                ans+=50;
            else
                ans+=5;
        }
        return ans;
    }
};

//Approach 2: @hongbin2,100ms
class Solution {
public:
    int romanToInt(string s) {
        int ans=0,len=s.length();
        if(s.find("IV")!=-1)ans-=2;
        if(s.find("IX")!=-1)ans-=2;
        if(s.find("XL")!=-1)ans-=20;
        if(s.find("XC")!=-1)ans-=20;
        if(s.find("CD")!=-1)ans-=200;
        if(s.find("CM")!=-1)ans-=200;
        
        for(int i=0;i<len;++i){
            if(s[i]=='I')ans+=1;
            else if(s[i]=='V')ans+=5;
            else if(s[i]=='X')ans+=10;
            else if(s[i]=='L')ans+=50;
            else if(s[i]=='C')ans+=100;
            else if(s[i]=='D')ans+=500;
            else if(s[i]=='M')ans+=1000;
        }
        
        return ans;
    }
};
