//1D BIT******************

ll bit[size];
ll n;

void update(ll pos,ll val)
{
    while(pos <= n)
    {
        bit[pos] += val;
        pos += pos&-pos;
    }
}

ll pref(ll pos)
{
    ll ans = 0;
    while(pos >= 1)
    {
        ans += bit[pos];
        pos -= pos&-pos;
    }
    return ans;
}

ll rsum(ll l,ll r,ll par)
{
    return pref(r) - pref(l-1);
}

//2D BIT******************

ll bit[2][size];
ll n;

void update(ll pos,ll val,ll par)
{
    while(pos <= n)
    {
        bit[par][pos] += val;
        pos += pos&-pos;
    }
}

ll pref(ll pos,ll par)
{
    ll ans = 0;
    while(pos >= 1)
    {
        ans += bit[par][pos];
        pos -= pos&-pos;
    }
    return ans;
}

ll rsum(ll l,ll r,ll par)
{
    return pref(r,par) - pref(l-1,par);
}

// Solved this Problem : https://www.codechef.com/ACJQ2017/problems/ATM0Q3
