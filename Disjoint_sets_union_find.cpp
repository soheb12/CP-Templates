//Union and Find with "Union By Rank" and "Path Compression"

pair< ll , ll > ds[size];//{ par, size }//Initialize all index parents to itslef to itself and size as 1
 
ll find_ds(ll x)
{
    ll ind = x;
    while(ds[ind].X != ind)
        ind = ds[ind].X;
    ds[x].X = ind;
    return ind;
}
 
void union_ds(ll u,ll v)//make sure to call this with representative node of both sets i.e first call find_ds on u,v
{
    if(ds[u].Y >= ds[v].Y)
    {
        ds[v].X = ds[u].X;
        ds[u].Y += ds[v].Y;
    }else
    {
        ds[u].X = ds[v].X;
        ds[v].Y += ds[u].Y;
    }
}

// Solved this problem : https://www.spoj.com/problems/NITTROAD/
// Solved this problem : https://www.spoj.com/problems/IITWPC4I/
