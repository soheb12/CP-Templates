//complexity Prim : O(V*V) and Kruskal : O(E*logE)

bool vis[size];
vector< pair<ll,ll> > adj[size];

ll prim(ll src)
{
    priority_queue< pair<ll,ll> , vector< pair<ll,ll> >, greater< pair<ll,ll> > >pq;
    ll mst_sum = 0,cc = -1;
    f(0,n)
    vis[i] = false;
    pq.push(mp(0, src));
    while(!pq.empty())
    {
        // Select the edge with minimum weight
        ll u = pq.top().Y;
        ll w = pq.top().X;
        pq.pop();
        // Checking for cycle
        if(vis[u] == true)
            continue;
        mst_sum += w;cc++;
        vis[u] = true;
        if(cc == n-1)return mst_sum;
        
        for(ll i = 0;i < adj[u].size();++i)
        {
            ll v = adj[u][i].X;
            ll w = adj[u][i].Y;
            if(vis[v] == false)
                pq.push(mp(w,v));
        }
    }
    return mst_sum;
}

Solved this problem : https://www.codechef.com/viewsolution/24288591
Solved this problem : https://www.codechef.com/viewsolution/24289364
