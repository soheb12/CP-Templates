const ll INF = 0x3f3f3f3f;
              /****** Travel through the parent array to get the path and dist[dest] distance to destination*******/
typedef pair<ll,ll> iPai
class Graph 
{ 
	ll V; 
	vector< pair<ll, ll> > *adj; 

public: 
	ll *parent;
	Graph(ll V); 
	void addEdge(ll u, ll v, ll w); 
	void shortestPath(ll s,ll d); 
}; 

Graph::Graph(ll V) 
{ 
	this->V = V; 
	adj = new vector<iPair> [V+1]; 
    parent = new ll[V+1];
} 

void Graph::addEdge(ll u, ll v, ll w) 
{ 
	adj[u].push_back(make_pair(v, w)); 
	adj[v].push_back(make_pair(u, w)); 
} 

void Graph::shortestPath(ll src,ll dest) 
{ 
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
	vector<ll> dist(V, INF);
	fill(parent,parent+V,-1);

	pq.push(make_pair(0, src)); 
	dist[src] = 0; 

	while (!pq.empty()) 
	{ 
		ll u = pq.top().second;// In PQ X = weight , Y = vertex
		pq.pop(); 

		vector< pair<ll, ll> >::iterator i; 
		for (i = adj[u].begin(); i != adj[u].end(); ++i) 
		{ 
			ll v = (*i).first; // In ADJ X = vertex , Y = weight
			ll weight = (*i).second; 

			if (dist[v] > dist[u] + weight) 
			{ 
				dist[v] = dist[u] + weight; 
				pq.push(make_pair(dist[v], v)); 
				parent[v] = u;
				if(v == dest)
				return;
			} 
		} 
	} 

} 

// Solved this problem : https://codeforces.com/contest/954/problem/D
