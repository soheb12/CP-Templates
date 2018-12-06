//******Make sure to assign n a value and then call the preprocessing functions

ll power(ll a,ll b,ll m){ll res = 1;while(b>0){if(b&1)res = (res*a)%m;b = b>>1;a = (a*a)%m;}return res;}

const ll p = 101;
ll pref[size],suff[size];
ll powers[size],n;
string s;

ll mod_inv(ll a)
{
    return power(a,mod-2,mod);
}

void computePowers() 
{ 
    powers[0] = 1; 
    for(ll i=1; i<=n; i++) 
        powers[i] = (powers[i-1]%mod * p%mod) %mod; 
} 

void computePrefixHash() 
{ 
    pref[0] = 0; 
    pref[1] = s[0]; 
    for (ll i=2; i<=n; i++) 
        pref[i] = ( pref[i-1]%mod + (s[i-1]%mod * powers[i-1]%mod) %mod ) %mod; 
}

void computeSuffixHash() 
{ 
    suff[0] = 0; 
    suff[1] = s[n-1]; 
    for (ll i=n-2, j=2; i>=0 && j<=n; i--,j++) 
        suff[j] = ( suff[j-1]%mod + (s[i]%mod * powers[j-1]%mod) %mod) %mod; 
} 

bool isPalin(ll l,ll r)
{
    ll hash_lr = ( (pref[r+1]-pref[l]+mod)%mod * mod_inv(powers[l])%mod ) %mod;
    ll hash_rl = ( (suff[n-l]-suff[n-r-1]+mod)%mod *  mod_inv(powers[n-r-1])%mod ) %mod; 
    if(hash_lr == hash_rl)
    return true;
    return false;
}
