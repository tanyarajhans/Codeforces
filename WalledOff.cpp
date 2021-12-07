int vis[252][252];
int low[252][252];  // in time of lowest ancestor that can be reached
int in[252][252];   // entry time
int timer = 0;
set<pair<int, int>> ap;
int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, vector<vector<int>>& matrix) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && matrix[nx][ny] == 0)
            dfs(nx, ny, matrix);
    }
}

void findAP(int x, int y, int px, int py, vector<vector<int>>& matrix) {
    vis[x][y] = 1;
    in[x][y] = low[x][y] = timer++;
    int c = 0;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= n || yy >= m || xx < 0 || yy < 0 || matrix[xx][yy] == 1) continue;
        if (xx == px && yy == py && px != -1 && py != -1) continue;
        if (vis[xx][yy] && px != -1 && py != -1) {  // back edge
            low[x][y] = min(low[x][y], in[xx][yy]);
        } else {
            findAP(xx, yy, x, y, matrix);
            low[x][y] = min(low[x][y], low[xx][yy]);
            if (low[xx][yy] >= in[x][y] && px != -1 && py != -1) ap.insert({x, y});
            c++;
        }
    }
    if (px == -1 && py == -1 && c > 1) ap.insert({x, y});
}

int solve(vector<vector<int>>& matrix) {
    n = matrix.size();
    m = matrix[0].size();
    memset(vis, 0, sizeof(vis));
    memset(low, 0, sizeof(vis));
    memset(in, 0, sizeof(vis));
    timer = 0;
    ap.clear();
    dfs(0, 0, matrix);
    if (vis[n - 1][m - 1] == 0) return 0;
    if (matrix[0][1] == 1 || matrix[1][0] == 1 || matrix[n - 2][m - 1] == 1 ||
        matrix[n - 1][m - 2] == 1)
        return 1;
    memset(vis, 0, sizeof(vis));
    findAP(0, 0, -1, -1, matrix);
    for (auto x : ap) {
        if ((x.first == 0 && x.second == 0) || (x.first == n - 1 && x.second == m - 1)) continue;
        cout << x.first << " " << x.second << endl;
        matrix[x.first][x.second] = 1;
    }
    // after blocking all AP check if path still exists
    memset(vis, 0, sizeof(vis));
    dfs(0, 0, matrix);
    cout << vis[n - 1][m - 1] << endl;
    if (ap.size() > 0 && !vis[n - 1][m - 1]) return 1;
    return 2;
}
