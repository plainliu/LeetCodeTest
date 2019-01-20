//2019.01.20
//Liu

//Contest977
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(auto &num:A)
            num*=num;
        sort(A.begin(),A.end());
        return A;
    }
};
