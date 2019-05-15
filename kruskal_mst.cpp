
vector< pair<ll , pair<ll,ll> > >edges;
vector< pair<ll,ll> >adj[size];
ll n,m,u,v,w;
pair<ll,ll>ds[size];//disjoint set par,rank

ll find_ds(ll x)
{
    ll ind = x;
    while(ds[ind].X != ind)
    {
        ind = ds[ind].X;
    }
    ds[x].X = ind;
    return ds[x].X;
}

void union_ds(ll x,ll y)
{
    if(ds[x].Y >= ds[y].Y)//x is par of y
    {
        ds[y].X = ds[x].X;
    }else
    ds[x].X = ds[y].X;
}

void solve()
{
        f(0,n)
        {
            ds[i].X = i;
            ds[i].Y = 0;
        }

        ll mst_sum = 0;
        for(auto it : edges)
        {
            u = it.Y.X;
            v = it.Y.Y;
            w = it.X;
            ll pu = find_ds(u);
            ll pv = find_ds(v);
            if(pu != pv)
            {
                mst_sum += w;
                union_ds(pu,pv);
            }
        }
        
}
