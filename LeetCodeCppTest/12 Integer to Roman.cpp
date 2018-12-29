/*
 *2018.12.29
 *Liu
 *
 *C++,string can use oprate'+',like append(string)
 *append(int,char)
 */
//Approach 1: Brute Force
class Solution {
public:
    string intToRoman(int num) {
        string str;
        //M
        int i=num/1000;
        while(i>0){str.append(1,'M');--i;}//0..3
        num=num%1000;
        //C
        i=num/100;
        if(i==9)str.append("CM");//900
        else if(i==4)str.append("CD");//400
        else{
            if(i/5==1)str.append("D");
            i=i%5;
            while(i>0){str.append("C");--i;}//0..3
        }
        num=num%100;
        //X
        i=num/10;
        if(i==9)str.append("XC");//90
        else if(i==4)str.append("XL");//40
        else{
            if(i/5==1)str.append("L");
            i=i%5;
            while(i>0){str.append("X");--i;}//0..3
        }
        num=num%10;
        //I
        i=num;
        if(i==9)str.append("IX");//9
        else if(i==4)str.append("IV");//4
        else{
            if(i/5==1)str.append("V");
            i=i%5;
            while(i>0){str.append("I");--i;}//0..3
        }
        return str;
    }
};
//Approach 2:using array A&B,actually also Brute Force
class Solution2 {
public:
    string intToRoman(int num) {
        string str;
        char A[4]={'I','X','C','M'};
        char B[3]={'V','L','D'};
        int i=0,index=3;
        for(int div=1000;div!=0;div=div/10,--index){//1000,100,10,1
            i=num/div;
            num%=div;
            if(i>=5){
                if(i==9){
                    str.append(1,A[index]);
                    str.append(1,A[index+1]);
                }
                else{//5..8
                    str.append(1,B[index]);
                    str.append(i%5,A[index]);
                }
            }
            else{//1..4
                if(i==4){
                    str.append(1,A[index]);
                    str.append(1,B[index]);
                }
                else//1..3
                    str.append(i,A[index]);
            }
        }
        return str;
    }
};
//Approach 2:more space for less time
//but running time nearly no change...
class Solution {
public:
    string intToRoman(int num) {
        string str;
        string A[4][10]={"","I","II","III","IV","V","VI","VII","VIII","IX",
                        "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
                        "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
                        "","M","MM","MMM"};
        int i=0,index=3;
        for(int div=1000;div!=0;div=div/10,--index){//1000,100,10,1
            i=num/div;
            num%=div;
            str=str+A[index][i];
        }
        return str;
    }
};
