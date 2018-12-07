//Push-Relabel Algorithm for Flows, Complexity: O(V^2 √E)
//To obtain the actual flow values, look at all edges with capacity > 0
//Zero capacity edges are residual edges

//Try using Dinic or Push Relable O(V^3) coz this might have a bad worst case 

struct edge
{
	ll from, to, cap, flow, index;
	edge(ll from, ll to, ll cap, ll flow, ll index):
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel
{
	static const ll INF=1e18;
	ll n;
	vector<vector<edge> > g;
	vector<ll> excess;
	vector<ll> height;

	PushRelabel(ll n):
		n(n), g(n), excess(n), height(n) {}

	void addEdge(ll from, ll to, ll cap)
	{
		g[from].pb(edge(from, to, cap, 0, g[to].size()));
		if(from==to)
			g[from].back().index++;
		g[to].pb(edge(to, from, 0, 0, g[from].size()-1));
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
	}

	void relabel(ll u)
	{
		ll d=2e5;
		for(auto &it:g[u])
		{
			if(it.cap-it.flow>0)
				d=min(d, height[it.to]);
		}
		if(d<INF)
			height[u]=d+1;
	}

	vector<ll> find_max_height_vertices(ll source, ll dest)
	{
		vector<ll> max_height;
		for(ll i=0;i<n;i++)
		{
			if(i!=source && i!=dest && excess[i]>0)
			{
				if(!max_height.empty() && height[i] > height[max_height[0]])
					max_height.clear();
				if(max_height.empty() || height[i] == height[max_height[0]])
					max_height.pb(i);
			}
		}
		return max_height;
	}

	ll max_flow(ll source, ll dest)
	{
		excess.assign(n, 0);
		height.assign(n, 0);
		height[source]=n;
		excess[source]=INF;
		for(auto &it:g[source])
			push(it);

		vector<ll> current;
		while(!(current = find_max_height_vertices(source, dest)).empty())
		{
			for(auto i:current)
			{
				bool pushed=false;
				for(auto &e:g[i])
				{
					if(excess[i]==0)
						break;
					if(e.cap - e.flow>0 && height[e.from] == height[e.to] + 1)
					{
						push(e);
						pushed=true;
					}
				}
				if(!pushed)
				{
					relabel(i);
					break;
				}
			}
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
