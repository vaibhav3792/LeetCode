class Solution {
public:
    int check(vector<vector<int>>& grid,int r, int c){
        for(int i = 0; i<grid.size(); i++){
            if(grid[i][c]==1 && i!=r) return 1; 
        }
        for(int j = 0; j<grid[0].size(); j++){
            if(grid[r][j]==1 && j!=c) return 1; 
        }
        return 0;
    }
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> indRowCount(m,0);
        vector<int> indColCount(n,0);

        int cnt = 0;
        for(int i =0; i<m; i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j]==1){
                    indRowCount[i]++;
                    indColCount[j]++;
                }
            }
        }

        for(int i =0; i<m; i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j]==1){
                    if(indRowCount[i]>1 || indColCount[j]>1) cnt++;
                }
            }
        }

        return cnt;
    }
};