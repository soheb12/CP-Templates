                                //********Array should be 1 indexed**********//

ll tree[size*4];
ll a[size];

void build(ll cur,ll a_beg,ll a_end)
{
    if(a_beg == a_end)
    tree[cur] = a[a_beg];
    else
    {
        ll mid = (a_beg+a_end)>>1;
        build(2*cur,a_beg,mid);
        build(2*cur+1,mid+1,a_end);
        tree[cur] = min(tree[2*cur],tree[2*cur+1]);
    }
}

ll query(ll cur,ll a_beg,ll a_end,ll q_beg,ll q_end)
{
    if(a_end < q_beg || a_beg > q_end)
    return LLONG_MAX;
    else if(a_beg >= q_beg && a_end <= q_end)
    return tree[cur];
	
    ll left,right;
    ll mid = (a_beg+a_end)>>1;
    left = query(2*cur,a_beg,mid,q_beg,q_end);
    right = query(2*cur+1,mid+1,a_end,q_beg,q_end);
    return min(left,right);
}

void update(ll cur,ll a_beg,ll a_end,ll pos,ll val)
{
    if(a_beg == a_end)
    tree[cur] = val;
    else
    {
        ll mid = (a_beg+a_end)>>1;
        if(pos <= mid)
        update(2*cur,a_beg,mid,pos,val);
        else
        update(2*cur+1,mid+1,a_end,pos,val);
        tree[cur] = min(tree[2*cur],tree[2*cur+1]);
    }
}
