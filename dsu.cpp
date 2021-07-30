int par[100005];
int size[100005];
    
int find(int u){
    if(u == par[u])
        return u;
    
    else
        return par[u]=find(par[u]);
}

void combine (int u, int v){
    u = find(u);
    v = find(v);
    
    if(u == v)
        return;
    
    else
    {
        if(size[u] > size[v])
        {
            par[v] = u;
            size[u] += size[v];
        }
        
        else
        {
            par[u] = v;
            size[v] += size[u];
        }
    
    }
    
}