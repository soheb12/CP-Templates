typedef struct TrieNode
{
    TrieNode* bit[2];
    ll cnt;
};

TrieNode* head;

TrieNode* getNode()
{
    TrieNode* node = new TrieNode();
    node->bit[0] = NULL;
    node->bit[1] = NULL;
    node->cnt=0;
    return node;
}

void insert(ll x)
{
    TrieNode* temp = head;
    for(int i=32;i>=0;i--)
    {
        int curbit = (x>>i)&1;
        if(temp->bit[curbit] == NULL)
        temp->bit[curbit] = getNode();
        temp = temp->bit[curbit];
        temp->cnt++;
    }
}

void remove(ll x)
{
    TrieNode* temp = head;
    for(int i=32;i>=0;i--)
    {
        int curbit = (x>>i)&1;
        temp = temp->bit[curbit];
        temp->cnt--;
    }
}

ll max_xor(ll x)
{
    TrieNode* temp = head;
    ll ans = 0;
    for(int i=32;i>=0;i--)
    {
        int curbit = (x>>i)&1;
        if(temp->bit[curbit^1] != NULL && temp->bit[curbit^1]->cnt > 0)
        {
            ans += (1LL << i);
            temp = temp->bit[curbit^1];
        }
        else
        temp = temp->bit[curbit];
    }
    return ans;
}

ll min_xor(ll x)
{
    TrieNode* temp = head;
    ll ans = 0;
    for(int i=30;i>=0;i--)
    {
        int curbit = (x>>i)&1;
        if(temp->bit[curbit] != NULL && temp->bit[curbit]->cnt > 0)
        {
            temp = temp->bit[curbit];
        }
        else
        {
            ans += (1LL << i);
            temp = temp->bit[curbit^1];
        }
    }
    return ans;
}

//Solved This problem : http://codeforces.com/contest/706/problem/D
//Solved This problem : http://codeforces.com/problemset/problem/948/D
