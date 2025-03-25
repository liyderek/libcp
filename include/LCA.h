struct LCA {
    int n, l, timer;
    vi tin, tout, visited, depth;
    vvc<int> up, qans;
    
    void init(int n) {
        this->n = n;
        tin.resize(n+1);
        tout.resize(n+1);
        l = ceil(log2(n));
        up.assign(n+1, vi(l+1));
        //qans.assign(n+1, vi(l+1, INF));
        visited.assign(n+1, 0);
        depth.resize(n+1);
    }
    
    void dfs(int c, int p, vvi &adj) {
        tin[c] = ++timer;
        up[c][0] = p;
        
        repe(i, 1, l) {
            up[c][i] = up[up[c][i-1]][i-1];
        }
        
        trav(u, adj[c]) {
            if(u != p) {
                depth[u] = depth[c]+1;
                visited[u] = 1;
                dfs(u, c, adj);
            }
        }
        
        tout[c] = ++timer;
    }
    
    void dfsq(int c, int p, int w, vvc<pr<int, int>> &adj) {
        tin[c] = ++timer;
        up[c][0] = p;
        qans[c][0] = w;
        
        repe(i, 1, l) {
            up[c][i] = up[up[c][i-1]][i-1];
            qans[c][i] = min(qans[c][i-1], qans[up[c][i-1]][i-1]);
        }
        
        trav(u, adj[c]) {
            if(u.fir != p) {
                depth[u.fir] = depth[c]+1;
                visited[u.fir] = 1;
                dfsq(u.fir, c, u.sec, adj);
            }
        }
        
        tout[c] = ++timer;
    }
 
    //is u ancestor of v?
    int isancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
 
    int lca(int u, int v) {
        if(isancestor(u, v)) return u;
        if(isancestor(v, u)) return v;
        for (int i = l; ~i; --i) {
            if (!isancestor(up[u][i], v)) u = up[u][i];
        }
        return up[u][0];
    }
    
    int lcaq(int u, int v) {
        if(isancestor(u, v)) {
            int aans = INF;
            for(int i = l; i >= 0; --i) {
                if(depth[up[v][i]] >= depth[u]) {
                    aans = min(aans, qans[v][i]);
                    v = up[v][i];
                }
            }
            return aans;
        } else if(isancestor(v, u)) {
            int aans = INF;
            for(int i = l; i >= 0; --i) {
                if(depth[up[u][i]] >= depth[v]) {
                    aans = min(aans, qans[u][i]);
                    u = up[u][i];
                }
            }
            return aans;
        }
        int temp = u, aans = INF, bans = INF;
        for(int i = l; i >= 0; --i) {
            if(!isancestor(up[temp][i], v)) {
                aans = min(aans, qans[temp][i]);
                temp = up[temp][i];
            }
        }
        aans = min(aans, qans[temp][0]);
        for(int i = l; i >= 0; --i) {
            if(!isancestor(up[v][i], u)) {
                bans = min(bans, qans[v][i]);
                v = up[v][i];
            }
        }
        bans = min(bans, qans[v][0]);
        return min(aans, bans);
    }
};
 
