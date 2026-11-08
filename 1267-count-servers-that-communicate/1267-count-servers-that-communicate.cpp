class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int serverRow = 0;
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowAloneServer(m, -1);
        vector<int> colServerCount(n, 0);

        for (int i = 0; i < m; i++) {
            serverRow = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    serverRow += 1;
                    colServerCount[j]++;
                    rowAloneServer[i] = j;
                }
            }
            if (serverRow > 1) {
                cnt += serverRow;
                rowAloneServer[i] = -1;
            }
        }

        for (int i = 0; i < m; i++) {
            if (rowAloneServer[i] != -1) {
                if (colServerCount[rowAloneServer[i]] > 1)
                    cnt++;
            }
        }
        return cnt;
    }
};