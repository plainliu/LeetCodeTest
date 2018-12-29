/*
 *2018.12.29
 *Liu
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
