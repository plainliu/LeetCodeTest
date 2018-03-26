/*
 *3.27
 *PlainLiu
 *
 *
 */
 
//1.0 time out
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=0;
        int x=0,h=0;//x*h
        for(int i=0;i<height.size()-1;++i){
            x=1;
            while(i+x<height.size()){
                h=(height[i]<=height[i+x]?height[i]:height[i+x]);
                max=(h*x>max?h*x:max);
                x++;
            }
        }
        return max;
    }
};

//2.0 time out
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,h=0;//x*h
        int max=(height.size()-1)*(height[0]<height[height.size()-1]?height[0]:height[height.size()-1]);
        for(int x=height.size()-2;x>0;--x){
            i=0;
            while(i+x<height.size()){
                h=(height[i]<height[i+x]?height[i]:height[i+x]);
                i++;
                if(h<max/x)continue;
                max=(h*x>max?h*x:max);
            }
        }
        return max;
    }
};
