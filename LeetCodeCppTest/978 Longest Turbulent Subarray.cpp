//2019.01.20
//Contest

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int len=A.size();
        if(len<2)return len;
        --len;
        int count=1,maxl=0;
        int flag=0;//>1;<-1;==0
        
        for(int i=0;i<len;++i){
            if(A[i]==A[i+1]){
                maxl=count>maxl?count:maxl;
                flag=0;
                count=1;
            }
            else if(flag){//1||-1
                if((A[i]>A[i+1]&&flag==-1)||(A[i]<A[i+1]&&flag==1)){
                    count++;
                    flag*=-1;
                }
                else{
                    maxl=count>maxl?count:maxl;
                    count=2;
                }
            }
            else{//0
                flag=A[i]>A[i+1]?1:-1;
                count++;
            }
        }
        maxl=count>maxl?count:maxl;
        return maxl;
    }
};
