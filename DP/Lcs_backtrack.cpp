// --------------------<optimizations>--------------------
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)\
#pragma GCC optimize("unroll-loops")

// -------------------</optimizations>--------------------
#include<bits/stdc++.h>
#define f(a,b) for(ll i=a;i<b;i++)
#define fb(a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define pl pair<ll,ll>
#define all(v) v.begin(),v.end()
using namespace std;
const ll mod=(1e+9)+7;
const ll sz = 2e5+9;
ll gcd(ll a,ll b) {if(b==0)return a;return gcd(b,a%b);}
ll power(ll a,ll b,ll m = mod) {ll res = 1;while(b>0){if(b&1)res = (res*a)%m;b = b>>1;a = (a*a)%m;}return res;}

void solve()
{
    while(1)
    {
        string a = "*",b = "*";
        cin>>a>>b;
        if(a == "*" && b == "*")break;
        ll dp[102][102] = {0};
        a = "*" + a;
        b = "*" + b;
        ll n = a.size(),m = b.size();
        
        //DYNAMIC PROGRAMMING TO GET LENGTH OF LCS, answer is in dp[n-1][m-1]
        for(ll i=1;i<n;i++)
        {
            for(ll j=1;j<m;j++)
            {
                if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1]+1;
                dp[i][j] = max(max(dp[i][j],dp[i-1][j]),dp[i][j-1]);
            }
        }
        
        //BACKTRACKING
        ll i=n-1,j=m-1;
        vector<char>ans;//storing word that has both the given string as subsequence in same order
        while(1)
        {
            if(i == 0 && j == 0)break;
            if(i == 0)
            {
                while(j!=0)
                ans.pb(b[j--]);
                break;
            }
            if(j == 0)
            {
                while(i!=0)
                ans.pb(a[i--]);
                break;
            }
            if(a[i] == b[j])
            {
                ans.pb(a[i]);//top left
                i--;j--;
            }else
            {
                if(dp[i-1][j] == dp[i][j])//top
                {
                    ans.pb(a[i]);
                    i--;
                }else//left
                {
                    ans.pb(b[j]);
                    j--;
                }
            }
        }
        reverse(all(ans));
        string res(all(ans));
        cout<<res<<endl;
    }
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
 
Problem Link : https://www.spoj.com/problems/ADFRUITS/
