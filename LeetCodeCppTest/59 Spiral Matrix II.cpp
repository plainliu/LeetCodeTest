/*
 *2019.01.19
 *Liu
 */

//依次放入1~n^2
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> cur(n);
        vector<vector<int>> res(n,cur);
        int s=n*n;
        for(int i=0,j=0,k=1;k<=s;){
            while(j<n&&res[i][j]==0)//right
                res[i][j++]=k++;
            ++i;--j;
            while(i<n&&res[i][j]==0)//down
                res[i++][j]=k++;
            --i;--j;
            while(j>=0&&res[i][j]==0)//left
                res[i][j--]=k++;
            ++j;--i;
            while(i>=0&&res[i][j]==0)//up
                res[i--][j]=k++;
            ++i;++j;
        }
        return res;
    }
};
