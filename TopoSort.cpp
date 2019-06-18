
vector<ll>adj[sz];
ll state[sz];//0 unvisited , 1 processing , 2 done processing
stack<ll>stk;

bool dfs(ll u)//will return false if there is a cycle otherwise print the content on the stack to get toposort
{
    if(state[u] == 2)
    return false;
    if(state[u] == 1)//back edge
    return true;
 
    state[u] = 1;
    for(ll v : adj[u])
    {
        if(dfs(v))
        return true;
    }
    state[u] = 2;
    stk.push(u);
    return false;
}

//Lexicographically smallest Toposort

ll n,m;//nodes , edges
vector<ll>adj[sz];//graph
ll in[sz];//indegress

void bfs()
{
    priority_queue<ll,vector<ll>, greater<ll> >pq;
    f(1,n+1)
    {
        if(in[i] == 0)//in stores all the indegrees of the initial graph
        pq.push(i);
    }
    while(!pq.empty())
    {
        ll u = pq.top();
        pq.pop();
        cout<<u<<" ";
        for(ll j : adj[u])
        {
            in[j]--;
            if(in[j] == 0)
            pq.push(j);
        }
    }
    cout<<endl;
}

// Solved this problem : https://codeforces.com/contest/1033/problem/C
// Solved this problem : https://www.spoj.com/problems/TOPOSORT/  (lexicographically smallest)

