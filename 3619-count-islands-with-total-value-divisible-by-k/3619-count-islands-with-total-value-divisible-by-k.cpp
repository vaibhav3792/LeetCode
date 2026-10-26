class Solution {
public:
    long long dfs(int r, int c, int m, int n, vector<vector<int>>& grid){
        long long sum = grid[r][c];
        grid[r][c] = 0;
        int drx[] = {1,-1,0,0};
        int dry[] = {0,0,1,-1};

        for(int i =0; i<4; i++){
            int nr = r + drx[i];
            int nc = c + dry[i];
            if(nr<m && nr>=0 && nc<n && nc>=0 && grid[nr][nc]>0){
                sum += dfs(nr,nc,m,n,grid);
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j]>0 && dfs(i,j,m,n,grid)%k==0){
                    cnt++;
                }
            }
        }
        return cnt;    
    }
};