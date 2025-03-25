struct dijkstra {
    int n, start;
    vi pred, dist;
    
    void init(int n, int start) {
        this->n = n;
        this->start = start;
        pred.assign(n+1, -1);
        dist.assign(n+1, INF);
    }
    
    void calc(vvc<pr<int, int>> &adj) {
        priority_queue<pr<int, int>, vc<pr<int, int>>, greater<pr<int, int>>> pq;
        dist[start] = 0;
        //{current distance, current node}
        pq.push({0, start});
        
        while(!pq.empty()) {
            auto info = pq.top();
            pq.pop();
            int cu = info.sec, cw = info.fir;
            if(cw != dist[cu]) continue;
            
            trav(next, adj[cu]) {
                //nv = to node, nw = edge weight between cu and nv
                int nv = next.fir, nw = next.sec;
                
                if(dist[cu]+nw < dist[nv]) {
                    dist[nv] = dist[cu]+nw;
                    pred[nv] = cu;
                    pq.push({dist[nv], nv});
                }
            }
        }
    }
};
 
        //Bellman-Ford - Average O(NM)
struct bellman_ford {
    int n, start, negative = -1;
    vi pred, dist;
    
    void init(int n, int start) {
        this->n = n;
        this->start = start;
        pred.assign(n+1, -1);
        dist.assign(n+1, INF);
    }
    
    void calcpos(vc<ar<int, 3>> &edg) {
        dist[start] = 0;
        int changed = 0;
        repl(i, 0, n) {
            trav(e, edg) {
                int cu = e[0], cv = e[1], cw = e[2];
                if(dist[cu] < INF){
                    if(dist[cv] > dist[cu]+cw) {
                        dist[cv] = dist[cu]+cw;
                        pred[cv] = cu;
                        changed = true;
                    }
                }
            }
            if(!changed) break;
        }
    }
    
    void calcneg(vc<ar<int, 3>> &edg) {
        dist[start] = 0;
        repl(i, 0, n) {
            trav(e, edg) {
                int cu = e[0], cv = e[1], cw = e[2];
                if(dist[cu] < INF){
                    if(dist[cv] > dist[cu]+cw) {
                        dist[cv] = max(-INF, dist[cu]+cw);
                        pred[cv] = cu;
                        negative = cv;
                    }
                }
            }
        }
    }
    
    bool is_negative() {
        return (negative != -1);
    }
};
