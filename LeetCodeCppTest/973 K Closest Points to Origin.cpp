//2019.01.13
//Contest
//973

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if(points.size()==0) return{};
        vector<vector<int>> Dist;
        vector<int> cur(2,0);
        int i=0;
        for(auto point:points){
            cur[0]=point[0]*point[0]+point[1]*point[1];
            cur[1]=i++;
            Dist.push_back(cur);
        }
        sort(Dist.begin(),Dist.end());
        for(int j=0;j<K;++j){
            Dist[j]=points[Dist[j][1]];
        }
        Dist.erase(Dist.begin()+K,Dist.end());
        return Dist;
    }
};
