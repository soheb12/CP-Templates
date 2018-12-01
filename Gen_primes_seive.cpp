 
const ll maxn = 32000;
 
vector<ll>prime;
void seive()
{
    bool isprime[maxn];
    
    f(0,maxn)
    isprime[i]=true;
    
    isprime[0]=isprime[1]=false;
    for(int i=2;i*i<maxn;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<maxn;j+=i)
            {
                isprime[j]=false;
            }
        }
        
    }
    
    for(int i=2;i<maxn;i++)
    {
        if(isprime[i])
        {prime.push_back(i);}
    }
}
 
void segmentedSeive(ll l,ll r)
{
    bool isprime[r-l+1];
    f(0,r-l+1)
    isprime[i]=true;
 
    for(ll i=0;prime[i]*prime[i] <= r;i++)
    {
        ll cur = prime[i];
        ll base = (l/cur)*cur;
        if(base<l)
        base += cur;
        for(ll j=base ; j<=r;j+=cur)
        isprime[j-l]=false;
        
        if(base==cur)
        isprime[base-l]=true;
        
    }
 
    for(ll i=0;i<r-l+1;i++)
    {
        if(isprime[i]&&l+i>1)
        cout<<i+l<<endl;
    }
}

//in solve
call seive() first
