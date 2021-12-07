int vis[252][252];
int dist[252][252];
pair<int,int> parent[252][252];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;

void dijkstra(int sx, int sy, vector<vector<int>>& matrix){
    set<pair<int, pair<int, int> > > s;
	s.insert({0, {sx,sy}});
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		vis[x.second.first][x.second.second]=1;
		vector<pair<int, pair<int, int> > > v;
		for(int i=0;i<4;i++)
		{
            int xx=sx+dx[i];
            int yy=sy+dy[i];
            if(xx<0 || xx>=n || yy<0 || yy>=m || vis[xx][yy])
                continue;
			v.push_back({matrix[xx][yy],{xx,yy}});
 
			if(dist[xx][yy] > dist[x.second.first][x.second.second] + matrix[xx][yy])
			{
				s.erase({dist[xx][yy], {xx,yy}});
				dist[xx][yy]=dist[x.second.first][x.second.second] + matrix[xx][yy];
				s.insert({dist[xx][yy], {xx,yy}});
				parent[xx][yy]=x.second;
			}
		}
	}
}

int solve(vector<vector<int>>& matrix, int row, int col, int erow0, int ecol0, int erow1, int ecol1) {
    n=matrix.size();
    m=matrix[0].size();
    
    for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
            dist[i][j]=1e9;
            parent[i][j]={-1,-1};
        }
	}
    dijkstra(row,col,matrix);
    vector<pair<int,int>> ans1, ans2,ans3,ans4;
    while(parent[erow0][ecol0].first!=-1){
        ans1.push_back({erow0,ecol0});
        erow0=parent[erow0][ecol0].first;
        ecol0=parent[erow0][ecol0].second;
    }
    for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
            dist[i][j]=1e9;
            vis[i][j]=0;
            parent[i][j]={-1,-1};
        }
	}
    dijkstra(erow0,ecol0,matrix);
    while(parent[erow1][ecol1].first!=-1){
        ans2.push_back({erow1,ecol1});
        erow1=parent[erow1][ecol1].first;
        ecol1=parent[erow1][ecol1].second;
    }
    for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
            dist[i][j]=1e9;
            vis[i][j]=0;
            parent[i][j]={-1,-1};
        }
	}
    dijkstra(row,col,matrix);
    while(parent[erow1][ecol1].first!=-1){
        ans3.push_back({erow1,ecol1});
        erow1=parent[erow1][ecol1].first;
        ecol1=parent[erow1][ecol1].second;
    }
    for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
            dist[i][j]=1e9;
            vis[i][j]=0;
            parent[i][j]={-1,-1};
        }
	}
    dijkstra(erow1,ecol1,matrix);
    while(parent[erow0][ecol0].first!=-1){
        ans4.push_back({erow0,ecol0});
        erow0=parent[erow0][ecol0].first;
        ecol0=parent[erow0][ecol0].second;
    }
    int c1=0,c2=0;
    for(auto &x: ans1){
        c1+=matrix[x.first][x.second];
    }
    for(auto &x: ans2){
        c1+=matrix[x.first][x.second];
    }
    for(auto &x: ans3){
        c2+=matrix[x.first][x.second];
    }
    for(auto &x: ans4){
        c2+=matrix[x.first][x.second];
    }

    return min(c1,c2);
}