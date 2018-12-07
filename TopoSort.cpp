
ll n;
vector<ll>adj[100005];
bool vis[100005];
stack<ll>s;
vector<ll>g;

void topo_util(ll v)
{
    vis[v] = true;
    
    for(ll i=0;i<adj[v].size();i++)
    {
        if(!vis[adj[v][i]])
        topo_util(adj[v][i]);
    }
    s.push(v);
}

void topo_sort()
{
    for(ll i=1;i<=n;i++)
    vis[i] = false;

    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        topo_util(i);
    }
    while(!s.empty())
    {
        g.pb(s.top());
        s.pop();
    }
}

// Solved this problem : https://codeforces.com/contest/1033/problem/C
