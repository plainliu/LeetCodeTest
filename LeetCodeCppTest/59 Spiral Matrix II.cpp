
//debuging
//wrong
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> cur(n);
        vector<vector<int>> res(n,cur);
        int s=n*n;
        for(int i=0,j=0,k=1;k<=s;){
            while(k<=s&&j<n&&res[i][j]==0)//right
                res[i][j++]=k++;
            --j;
            while(i<n&&res[i][j]==0)//down
                res[i++][j]=k++;
            --i;
            while(j>=0&&res[i][j]==0)//left
                res[i][j--]=k++;
            ++j;
            while(res[i][j]==0)//up
                res[i--][j]=k++;
            ++i;
        }
        return res;
    }
};
