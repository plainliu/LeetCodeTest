


//wrong
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0)return 0;
        int res=0;
        int flag=(dividend<0)^(divisor<0)?-1:1;
        bool mindvd=false;
        if(dividend==INT_MIN){//if result overflows.
            if(divisor==-1)
                return INT_MAX;
            if(divisor==INT_MIN)
                return 1;
            dividend+=abs(divisor);
            mindvd=true;          
        }
        else if(divisor==INT_MIN)
            return 0;
        int dvd=abs(dividend),div=abs(divisor);//now both of their abs() are in[0,2^31-1]
        if(dvd>=div){
            int count=0;
            while(dvd>=(div<<1)&&count<30){
                div<<=1;
                count++;
            }
            if(dvd==div){
                if(mindvd)
                    return flag*(1<<count+1);
                return flag*(1<<count);
            }
            while(count>=0){
                res<<=1;
                if(dvd>=div){
                    res+=1;
                    dvd-=div;
                }
                div>>=1;
                count--;
            }
        }
        if(mindvd)res+=1;
        return flag*res;
    }
};
