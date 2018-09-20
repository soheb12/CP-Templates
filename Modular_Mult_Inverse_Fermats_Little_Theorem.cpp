#define ll long long
//This Method Works Only When M is Prime, So Carefull While Using It.
ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}

ll power(ll a,ll b,ll m)
{
    ll res = 1;
    while(b>0)
    {
        if(b&1)
        res = (res*a)%m;
        b = b>>1;
        a = (a*a)%m;
    }
    return res;
}

ll mod_inv(ll a,ll m)
{
    ll g = gcd(a,m);
    if(g!=1)
    return -1;
    return power(a,m-2,m);
}
