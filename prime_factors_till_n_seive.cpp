ll *seive(ll n)
{
    ll *spf = new int[n+1];
    for(ll i=1;i<=n;i++)
    {
        if(i%2==0)
        spf[i] = 2;
        else
        spf[i] = i;
    }

    for(ll i=3;i*i<=n;i++)
    {
        if(spf[i]==i)
        {
            for(ll j=i*i;j<=n;j+=i)
            {
                if(spf[j]==j)
                spf[j] = i;
            }
        }
    }
    return spf;
}

map<ll,ll> gen_prime_factors(ll n,ll* spf)
{
    map<ll,ll> m;
    while(n>1)
    {
        m[spf[n]]++;
        n = n/spf[n];
    }
    return m;
}
