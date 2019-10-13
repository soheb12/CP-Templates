// The Segment Tree is rooted at 1 so make sure to pass initial node of seg tree as 1

//This is for Range Sum

ll n,q;
ll tree[4*sz];
ll lazy[4*sz];
ll a[sz];

void build(ll cur,ll a_beg,ll a_end)
{
    if(a_beg == a_end)
    tree[cur] = a[a_beg];
    else
    {
        ll mid = (a_beg+a_end)>>1;
        build(2*cur,a_beg,mid);
        build(2*cur+1,mid+1,a_end);
        tree[cur] = tree[2*cur] + tree[2*cur+1];
    }
}

void update(ll cur,ll a_beg,ll a_end,ll q_beg,ll q_end,ll val)
{
    if(lazy[cur] != 0)
    {
        tree[cur] += (a_end - a_beg + 1)*lazy[cur];//these many elements are under this node
        if(a_beg != a_end)
        {
            lazy[2*cur] += lazy[cur];         
            lazy[2*cur + 1] += lazy[cur];
        }
        lazy[cur] = 0;//this node values are decomposed to its childrens
    }

    if(a_beg > q_end || a_end < q_beg)//node out of range
    return;

    if(a_beg >= q_beg && a_end <= q_end)//node completely within the range
    {
        tree[cur] += (a_end - a_beg + 1)*val;
        if(a_beg != a_end)//not a leaf
        {
            lazy[2*cur] += val;//childs are yet to be updated
            lazy[2*cur+1] += val;
        }
        return;//no need to go any futher for now
    }

    ll mid = a_beg + (a_end-a_beg)/2;//Partial Overlap so go in both the directions until complete overlap
    update(2*cur,a_beg,mid,q_beg,q_end,val);
    update(2*cur+1,mid+1,a_end,q_beg,q_end,val);
    tree[cur] = tree[2*cur] + tree[2*cur + 1];
}

ll query(ll cur,ll a_beg,ll a_end,ll q_beg,ll q_end)
{
    if(lazy[cur] != 0)
    {
        tree[cur] += (a_end - a_beg + 1)*lazy[cur];
        if(a_beg != a_end)//not a leaf
        {
            lazy[2*cur] += lazy[cur];
            lazy[2*cur+1] += lazy[cur];
        }
        lazy[cur] = 0;
    }
    if(a_beg > q_end || a_end < q_beg)//No overlap
    return 0;

    if(a_beg >= q_beg && a_end <= q_end)//Complete Overlap
    return tree[cur];

    ll mid = a_beg + (a_end - a_beg)/2;
    ll p1 = query(2*cur,a_beg,mid,q_beg,q_end);
    ll p2 = query(2*cur+1,mid+1,a_end,q_beg,q_end);
    return p1+p2;
}

// This is for Range Max

// The Segment Tree is rooted at 1 so make sure to pass initial node of seg tree as 1

ll tree[4*sz];
ll lazy[4*sz];
ll a[sz];
ll maxn = 200002;

void build(ll cur,ll a_beg,ll a_end)
{
    if(a_beg == a_end)
    tree[cur] = a[a_beg];
    else
    {
        ll mid = (a_beg+a_end)>>1;
        build(2*cur,a_beg,mid);
        build(2*cur+1,mid+1,a_end);
        tree[cur] = tree[2*cur] + tree[2*cur+1];
    }
}

ll query(ll cur,ll a_beg,ll a_end,ll q_beg,ll q_end)
{
    if(lazy[cur] != 0)
    {
        tree[cur] = lazy[cur];
        if(a_beg != a_end)//not a leaf
        {
            lazy[2*cur] = lazy[cur];
            lazy[2*cur+1] = lazy[cur];
        }
        lazy[cur] = 0;
    }
    if(a_beg > q_end || a_end < q_beg)//No overlap
    return 0;

    if(a_beg >= q_beg && a_end <= q_end)//Complete Overlap
    return tree[cur];

    ll mid = a_beg + (a_end - a_beg)/2;
    ll p1 = query(2*cur,a_beg,mid,q_beg,q_end);
    ll p2 = query(2*cur+1,mid+1,a_end,q_beg,q_end);
    return max(p1,p2);
}

void update(ll cur,ll a_beg,ll a_end,ll q_beg,ll q_end,ll val,ll mx)
{
    if(lazy[cur] != 0)
    {
        tree[cur] = lazy[cur];//these many elements are under this node
        if(a_beg != a_end)
        {
            lazy[2*cur] = lazy[cur];         
            lazy[2*cur + 1] = lazy[cur];
        }
        lazy[cur] = 0;//this node values are decomposed to its childrens
    }

    if(a_beg > q_end || a_end < q_beg)//node out of range
    return;

    if(a_beg >= q_beg && a_end <= q_end )//node completely within the range
    {
        tree[cur] = val;
        if(a_beg != a_end)//not a leaf
        {
            lazy[2*cur] = val;//childs are yet to be updated
            lazy[2*cur+1] = val;
        }
        return;//no need to go any futher for now
    }

    ll mid = a_beg + (a_end-a_beg)/2;//Partial Overlap so go in both the directions until complete overlap
    update(2*cur,a_beg,mid,q_beg,q_end,val,mx);
    update(2*cur+1,mid+1,a_end,q_beg,q_end,val,mx);
    if(2*cur >= 4*sz || 2*cur+1 >= 4*sz)
        return;
    tree[cur] = max(tree[2*cur] , tree[2*cur + 1]);
}

//Solved this problem : https://www.spoj.com/problems/HORRIBLE/
//Solved this problem : https://www.codechef.com/ACD2019/problems/LYPLNK/
