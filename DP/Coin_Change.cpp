// Minimum number coins required to make sum S

void solve()
{
    ll s,n;
    cin>>s>>n;//s is sum and n number of coins available
    ll a[n];
    f(0,n)
    cin>>a[i];
    vector<ll>dp(252,mod);
    dp[0] = 0;//one way to get sum 0
    for(ll i=0;i<n;i++)// If you had only coins till i
    for(ll j=1;j<=s;j++)
        if(j - a[i] >= 0)
            dp[j] = min(dp[j],dp[j-a[i]]+1);// Changing min number of coins to get sum j with this new coin a[i]
    cout<<dp[s]<<endl;
}

// Total number of ways to get change S

void solve()
{
    ll s,n;
    cin>>s>>n;s is sum and n number of coins available
    ll a[n];
    f(0,n)
    cin>>a[i];
    ll dp[252] = {0};
    dp[0] = 1;//one way to get sum 0
    for(ll i=0;i<n;i++)// If you had only coins till i
        for(ll j=1;j<=s;j++)
            if(j - a[i] >= 0)
            dp[j] += dp[j-a[i]];// adding this new coin to the previously possible combinations 
    cout<<dp[s]<<endl;
}

// Check this thread : https://apps.topcoder.com/forums/?module=Thread&threadID=700080&start=0
