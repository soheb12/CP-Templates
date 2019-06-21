//Call dfs over every vertex and then call kosaraju()

ll n,m;
vector<ll>adj[sz];
vector<ll>rev[sz];

stack<ll>stk;
bool vis[sz];
ll id[sz],cc;
vector<ll>comp[sz];//all comps stored with their id's

void dfs(ll u)
{
    if(vis[u])
    return;
    vis[u] = true;
    for(ll v : adj[u])
    dfs(v);
    stk.push(u);//proceesed the sub graph
}

void kosaraju()
{
    cc = 1;
    f(1,n+1)
    id[i] = -1;

    queue<ll>q;
    while(stk.size() > 0)
    {
        ll u = stk.top();
        stk.pop();
        if(id[u] != -1)//already processed
        continue;

        id[u] = cc;
        q.push(u);
        //bfs
        while(q.size() > 0)
        {
            ll ss = q.front();
            q.pop();
            comp[cc].pb(ss);
            for(ll dd : rev[ss])
            {
                if(id[dd] == -1)
                {
                    id[dd] = cc;
                    q.push(dd);
                }
            }
        }
        cc++;//new comp
    }
}

//Solved this problem : https://www.codechef.com/viewsolution/24887179

