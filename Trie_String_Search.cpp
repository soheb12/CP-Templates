struct TrieNode
{
    struct TrieNode* child[26];//0 -> a
    int cnt;                   //no of times a char has come in a prefix
    bool EOW;                  //end of word
};

struct TrieNode* head;

struct TrieNode* getNode()
{
    struct TrieNode* node = new TrieNode();
    node->cnt = 0;
    node->EOW = false;
    for(int i=0;i<26;i++)
        node->child[i] = NULL; 
    return node;
}

void insert(string key)
{
    struct TrieNode* temp = head;
    for(int i=0;i<key.length();i++)
    {
        int ind = int(key[i]) - 'a';
        if(temp->child[ind] == NULL)
            temp->child[ind] = getNode();
        temp->child[ind]->cnt++;
        temp = temp->child[ind];
    }
    temp->EOW = true;
}

int search(string key)
{
    struct TrieNode* temp = head;
    for(int i=0;i<key.length();i++)
    {
        int ind = int(key[i]) - 'a';
        if(temp->child[ind] == NULL)
            return 0;
        temp = temp->child[ind];
    }
    return temp->cnt;
}


//Solved this problem https://www.hackerrank.com/challenges/contacts/problem
