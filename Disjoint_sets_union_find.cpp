//Replace map with unordered_map when using c++14^ 
//Union and Find with "Union By Rank" and "Path Compression"

struct Node{
    ll data;
    Node* par;
    ll rank;
};

map<ll,Node*>m;

void makeSet(ll data)
{
    Node* node = new Node();
    node->data = data;
    node->rank = 0;
    node->par = node;
    m[data] = node;
}

Node* findSet(Node* node)
{
    Node* par = node->par;
    if(par == node)
    return par;
    node->par = findSet(node->par);//path Compression
    return node->par;
}

ll findSet(ll data)
{
    return findSet(m[data])->data;
}

bool unionSet(ll data1,ll data2)//will return true if data1 and data2 were in different sets else false
{
    Node* node1 = m[data1];
    Node* node2 = m[data2];
    Node* p1 = findSet(node1);
    Node* p2 = findSet(node2);

    if(p1 == p2)//if in same set already
    return false;

    if(p1->rank >= p2->rank)//p1 is bigger tree
    {
        p1->rank = (p1->rank == p2->rank)? (p1->rank + 1) : (p1->rank);//Now since p1 is bigger than p2 if both were of some size
        p2->par = p1;
    }else
    p1->par = p2;//no need to update rank of p2 as anyways p2 has higher rank

    return true;
}

void solve()
{
        makeSet(1);
        makeSet(2);
        makeSet(3);
        makeSet(4);
        makeSet(5);
        makeSet(6);
        makeSet(7);

        unionSet(1, 2);
        unionSet(2, 3);
        unionSet(4, 5);
        unionSet(6, 7);
        unionSet(5, 6);
        unionSet(3, 7);

        cout<<findSet(1)<<endl;
        cout<<findSet(2)<<endl;
        cout<<findSet(3)<<endl;
        cout<<findSet(4)<<endl;
        cout<<findSet(5)<<endl;
        cout<<findSet(6)<<endl;
        cout<<findSet(7)<<endl;
}
