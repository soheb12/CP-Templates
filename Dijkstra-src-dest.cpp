const ll INF = LLONG_MAX;
vector< pair<ll,ll> >adj[size];
ll dist[size],n,m;

ll dijstra(ll x)
{
    f(0,n+1)
    dist[i] = INF;

    priority_queue< pair<ll,ll> , vector< pair<ll,ll> > , greater< pair<ll,ll> > >pq;
    pq.push(mp(0,x));
    dist[x] = 0;

    while(!pq.empty())
    {
        ll u = pq.top().Y;
        pq.pop();

        for(auto it : adj[u])
        {
            ll v = (it).X;
            ll w = (it).Y;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push(mp(dist[v],v));
            }
        }
    }

}

// Solved this problem : https://codeforces.com/contest/954/problem/D
