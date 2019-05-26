vector< ll > adj[size],tin,low;//time in and low time
bool vis[size];
set< pair<ll,ll> >bridge;//to store all the bridges
ll timer = 0;

void dfs(ll u,ll p)
{
    vis[u] = true;
    tin[u] = low[u] = timer++;//since this node is visited for the first time
    int c = 0;//child count
    for(ll v : adj[u])
    {
        if(v == p)continue;
        if(vis[v])
        low[u] = min(low[u],tin[v]);//visited u after v
        else
        {
            c++;//new child
            dfs(v,u);
            low[u] = min(low[u],low[v]);//visited v after u
            if(low[v] > tin[u])//no backedge for v so (u,v) is a bridge
                bridge.insert(mp(u,v));
        }
    }
}

void solve()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;

        f(0,n)
        vis[i] = false,adj[i].clear();
        bridge.clear();
        tin.assign(n,-1);
        low.assign(n,-1);
        timer = 0;

        ll u,v;
        f(0,m)
        {
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(0,-1);
        ll ans = bridge.size();//here bridge has all the bridges
        cout<<ans<<endl;
    }
}
