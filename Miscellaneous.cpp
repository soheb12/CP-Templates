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
ll power(ll a,ll b,ll m = mod) {ll res = 1;while(b>0){if(b&1)res = (res*a)%m;b = b>>1;a = (a*a)%m;}return res;}


void solve()
{
    //lambda functions
    /*auto maxx = [](int a[],int n){
        int ans = INT_MIN;
        f(0,n)
        ans = max(ans,a[i]);
        return ans;
    };
    int n;
    cin>>n;
    int a[n];
    f(0,n)
    cin>>a[i];
    cout<<maxx(a,n)<<endl;*/
    
    //struct functions
    /*struct st{
        int give(int a,int b){
            return a*b;
        }
    };
    st s;
    int v = s.give(2,3);
    cout<<v<<endl;*/
    
    //comp function
    /*struct comp{
        bool operator()(const int& a,const int& b){
            return a>b;
        }
    };
    set<int,comp>s;
    s.insert(1);
    s.insert(2);
    int v = *(s.begin());
    cout<<v<<endl;*/
    
    //StringStream int to string
    /*stringstream str;
    int a;
    cin>>a;
    str << a;
    string s = str.str();
    cout<<s<<endl;*/
    
    //stringstream string to int
    /*int a;
    string s;
    cin>>s;
    stringstream ss(s);
    ss >> a;
    cout<<a*10<<endl;*/
    
    //stringstream words processing
    /*string s,t;
    int x;
    cin>>x;cin.ignore();
    getline(cin,s);//give words with spaces
    stringstream ss(s);
    while(ss >> t)
    cout<<t<<endl;*/
    
    //itoa
    /*vector<int>v(20);
    iota(all(v),0);
    for(auto x : v)
    cout<<x<<" ";
    cout<<endl;*/
    
    //comp2
    /*vector<int>v(20);
    iota(all(v),1);
    sort(all(v),[&](int a,int b){return a > b;});//sorting in descending order
    f(0,v.size())
    cout<<v[i]<<" ";
    cout<<endl;*/
    
    //emplace and pair input 
    /*set< pair<int,int> >a,b;
    f(0,10)
    a.emplace(i,i+1);//emplace_back for vector
    for(auto& x: a)
    cout<<x.X<<"--"<<x.Y<<" ";
    cout<<endl;*/
    
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
