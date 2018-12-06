//******************Find the max in lps[] to get longest palindrome substring

ll lps[2*size];
ll n,k;

string convertToNewString(string s)
{
    string res = "@";
    for(ll i=0;i<s.size();i++)
    {
        res += '#' + s.substr(i,1);
    }
    res += "#$";
    return res;//new length is 2*n+3
}

void generatePalindromeArray(string str)
{
    string s = convertToNewString(str); //pre-processing the string
    ll c = 0,r = 0;//center and radius(length)
    for(ll i=1;i<s.size()-1;i++)
    {
        ll i_mirror = c - (i-c); //find the corresponding letter in the palidrome subString
        if(i < r) //if i is still in boundary then it is atleast this length
        lps[i] = min(lps[i_mirror] , r - i);
        while(s[i + 1 + lps[i]] == s[i - (1 + lps[i])]) //expanding around center i
        lps[i]++;
        if(i + lps[i] > r) //Update c,r in case if the palindrome centered at i expands past r
        {
            c = i; //next center
            r = i + lps[i]; //new boundary or radius
        }
    }
}

// To consider only substrings of over length n in a doubled string consider range n+1 to 3*n-1 and increments of 2
