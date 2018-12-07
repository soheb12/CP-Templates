//                                            ****Vertices are 0 indexed****
//                                   ****https://www.youtube.com/watch?v=0hI89H39USg****

struct edge
{
	ll from, to, cap, flow, index;
	edge(ll from, ll to, ll cap, ll flow, ll index):
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel
{
	ll n;
	vector<vector<edge> > g;
	vector<ll> excess;
	vector<ll> height, active, count;
	queue<ll> Q;

	PushRelabel(ll n):
		n(n), g(n), excess(n), height(n), active(n), count(2*n) {}

	void addEdge(ll from, ll to, ll cap)
	{
		g[from].pb(edge(from, to, cap, 0, g[to].size()));
		if(from == to)
			g[from].back().index++;
		g[to].pb(edge(to, from, 0, 0, g[from].size()-1));
	}

	void enqueue(ll v)
	{
		if(!active[v] && excess[v] > 0)
		{
			active[v]=true;
			Q.push(v);
		}
	}

	void push(edge &e)
	{
		ll amt=(ll)min(excess[e.from], (ll)e.cap - e.flow);
		if(height[e.from]<=height[e.to] || amt==0)
			return;
		e.flow += amt;
		g[e.to][e.index].flow -= amt;
		excess[e.to] += amt;
		excess[e.from] -= amt;
		enqueue(e.to);
	}

	void relabel(ll v)
	{
		count[height[v]]--;
		ll d=2*n;
		for(auto &it:g[v])
		{
			if(it.cap-it.flow>0)
				d=min(d, height[it.to]+1);
		}
		height[v]=d;
		count[height[v]]++;
		enqueue(v);
	}

	void gap(ll k)
	{
		for(ll v=0;v<n;v++)
		{
			if(height[v]<k)
				continue;
			count[height[v]]--;
			height[v]=max(height[v], n+1);
			count[height[v]]++;
			enqueue(v);
		}
	}

	void discharge(ll v)
	{
		for(ll i=0; excess[v]>0 && i<g[v].size(); i++)
			push(g[v][i]);
		if(excess[v]>0)
		{
			if(count[height[v]]==1)
				gap(height[v]);
			else
				relabel(v);
		}
	}

	ll max_flow(ll source, ll dest)
	{
		count[0] = n-1;
		count[n] = 1;
		height[source] = n;
		active[source] = active[dest] = 1;
		for(auto &it:g[source])
		{
			excess[source]+=it.cap;
			push(it);
		}
		while(!Q.empty())
		{
			ll v=Q.front();
			Q.pop();
			active[v]=false;
			discharge(v);
		}

		ll max_flow=0;
		for(auto &e:g[source])
			max_flow+=e.flow;

		return max_flow;
	}
};

void solve()
{
    ll n,m,u,v,w;
	cin>>n>>m;
	PushRelabel pr(n);
	for(ll i=0;i<m;i++){
		cin>>u>>v>>w;
		if(u!=v){
		pr.addEdge(u-1,v-1,w);
		pr.addEdge(v-1,u-1,w);}
	}
	cout<<pr.max_flow(0,n-1)<<endl;
}

// original source : https://github.com/jaehyunp/stanfordacm/blob/master/code/PushRelabel.cc

// Solved this problem : https://www.spoj.com/problems/FASTFLOW/
