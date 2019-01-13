//2019.01.13
//Contest
//976

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end());
        int p=0;
        for(int i=A.size()-1,l=0,r=0;i>1;--i){
            if(p>A[i]*3)return p;
            l=i-2;
            r=i-1;
            if(A[r]<=A[i]/2)
                continue;
            if(A[l]+A[r]>A[i])
                p=A[l]+A[r]+A[i]>p?A[l]+A[r]+A[i]:p;
        }
        return p;
    }
};
