class Solution {
    int n,m;

    vector<vector<int>> dp;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        n=g.size();
        m=g[0].size();
        if(g[n-1][m-1]==1) return 0;

        dp.assign(n,vector<int>(m,-1));
        return find(g,0,0);
        
    }

    int find(vector<vector<int>>& grid,int i,int j){
        if(i==n || j==m || grid[i][j]==1) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int r=find(grid,i,j+1);
        int d=find(grid,i+1,j);
        return dp[i][j] =r+d;
    }
};