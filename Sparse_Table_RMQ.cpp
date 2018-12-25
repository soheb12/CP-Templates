ll sparse[32][size];
ll n,a[size];

void precompute()
{
    f(0,n)sparse[0][i] = i;    
    for(ll i=1;power(2,i) < n;i++)
    for(ll j=0; j+power(2,i)-1 < n;j++)
    {
        if(a[sparse[i-1][j]] < a[sparse[i-1][j+power(2,i-1)]] )
            sparse[i][j] = sparse[i-1][j];
        else
            sparse[i][j] = sparse[i-1][j+power(2,i-1)];
    }
}

ll RMQ(ll l,ll r)//0 indexed l,r
{
    ll len = r - l + 1;
    ll k = floor(log2(len));
    return min( a[ sparse[k][l] ] , a[ sparse[k][l + len-power(2,k)] ]);
}
