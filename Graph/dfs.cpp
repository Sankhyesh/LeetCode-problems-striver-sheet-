int *bfs(struct graph *g, int n, int m) {
    // your code here
    vector<int> bfs;
    vecot<int, int> vis(n+1, 0);
    
    
    // for connectoed componets 
    for(int i = 0; i<=n; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                
                for(auto it: g[node]){
                    if(!vis[it]){
                        q.push[it];
                        vis[it] = 1;
                    }
                }
            }
            
        }
    }
    
}
