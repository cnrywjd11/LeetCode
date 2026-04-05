class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool visited[301][301];
    int m, n;
    int numIslands(vector<vector<char>>& grid) {
        memset(visited, 0, sizeof(visited));
        m = grid.size();
        n = grid[0].size();
        int num = 0;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    num++;
                    dfs(i, j, grid);
                }
            }
        }

        return num;
    }

    bool isInRange(int y, int x) {
        if(0<=y && y <m && 0<=x && x <n) return true;
        return false;
    }

    void dfs(int y, int x, vector<vector<char>>& grid) {
        visited[y][x] = true;
        cout << y << x << endl;
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(isInRange(ny, nx) && grid[ny][nx] == '1' && !visited[ny][nx]) {
                dfs(ny, nx, grid);
            }
        }
    }
};