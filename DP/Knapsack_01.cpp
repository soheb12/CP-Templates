#include<bits/stdc++.h>
#define f(a,n) for(ll i=a;i<n;i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define all(v) v.begin(),v.end()
using namespace std;
const ll mod=(1e+9)+7;
const ll size = 2e5+9;
ll gcd(ll a,ll b) {if(b==0)return a;return gcd(b,a%b);}
ll power(ll a,ll b,ll m) {ll res = 1;while(b>0){if(b&1)res = (res*a)%m;b = b>>1;a = (a*a)%m;}return res;}
 
ll dp[2001][2001];//dp[i][j] = max(Picking i^th item,Not picking i^th item)
 
void solve()
{
    ll s,n;//knapsack size, Total items
    cin>>s>>n;
    ll w[n+1],v[n+1];
    f(1,n+1)
        cin>>w[i]>>v[i];
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<s+1;j++)
        {
            if(j < w[i])
            dp[i][j] = dp[i-1][j];
            else
            dp[i][j] = max(v[i] + dp[i-1][j-w[i]] , dp[i-1][j]);//picking , not picking
        }
    }
    cout<<dp[n][s]<<endl;
}
 
int main()
{
    #ifdef JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    clock_t beg = clock();
    solve();
    clock_t end = clock();
    fprintf(stderr, "%.3f sec, Copyright %c 2019 Skyscraper. \n", double(end - beg) / CLOCKS_PER_SEC , 184);
    return 0;
} 

//Problem link :https://www.spoj.com/problems/KNAPSACK/
