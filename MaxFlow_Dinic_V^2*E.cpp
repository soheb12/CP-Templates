//*************************************complexity is O(V^2*E)

struct edge{
	ll v;
	ll flow,c;
	ll rev;
	edge(ll v,ll flow,ll c,ll rev)
	{
		this->v = v;this->flow = flow;this->c = c;this->rev = rev;
	}
};
 
vector<edge>adj[size];
ll level[size];
ll ptr[size];
 
void addedge(ll u,ll v,ll w){
	edge a(v,0,w,adj[v].size());
	edge b(u,0,w,adj[u].size());
	adj[u].push_back(a);
	adj[v].push_back(b);
}
 
bool bfs(ll s,ll t){
	memset(level,-1,sizeof level);
	level[s]=0;
	queue<ll>q;
	q.push(s);
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		for(ll i=0;i<adj[u].size();i++){
			if(level[adj[u][i].v]<0&&adj[u][i].flow<adj[u][i].c){
				level[adj[u][i].v]=level[u]+1;
				q.push(adj[u][i].v);
			}
		}
	}
	return level[t]<0?0:1;
}
 
ll dfs(ll u,ll flow,ll t){
	if(u==t)
	return flow;

	for(;ptr[u]<adj[u].size();ptr[u]++){
		if(level[adj[u][ptr[u]].v]==level[u]+1 && adj[u][ptr[u]].flow<adj[u][ptr[u]].c)
		{
			ll cur_flow=min(flow*1LL,adj[u][ptr[u]].c-adj[u][ptr[u]].flow*1LL);
			ll tm_flow=dfs(adj[u][ptr[u]].v,cur_flow,t);
			if(tm_flow>0)
			{
				adj[u][ptr[u]].flow+=tm_flow;
				adj[adj[u][ptr[u]].v][adj[u][ptr[u]].rev].flow-=tm_flow;
				return tm_flow;
			}
		}
	}
	return 0;
}
 
ll Dinic(ll s,ll t){
	if(s == t)
	return -1;
	ll total_flow=0;
	while(bfs(s,t))
	{
		memset(ptr,0,sizeof ptr);
		while(ll flow=dfs(s,LLONG_MAX,t))
			total_flow+=flow;
	}
	return total_flow;
}

// Solved this problem : https://www.spoj.com/problems/FASTFLOW/
