#define ll long long
#define pb push_back

bool isSmaller(string s1,string s2)
{
    ll n1=s1.size(),n2=s2.size();
    if(n1<n2)
    return true;
    if(n1>n2)
    return false;

    for(ll i=0;i<n1;i++)
    {
        if(s1[i]<s2[i])
        return true;
        else if(s1[i]>s2[i])
        return false;
    }
    return false;
}
                                                        //Subtraction
string operator-(string s1,string s2)
{
    int cc=0;
    if(isSmaller(s1,s2))
    {swap(s1,s2);cc=1;}
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    string res;
    ll n1=s1.size(),n2=s2.size(),carry=0,diff;
    for(ll i=0;i<n2;i++)
    {
        diff = (s1[i]-'0') - (s2[i]-'0') - carry;
        if(diff<0)
        {diff+=10;carry=1;}
        else
        carry=0;
        res.pb(diff+'0');
    }
    for(ll i=n2;i<n1;i++)
    {
        diff = (s1[i]-'0')-carry;
        if(diff<0)
        {diff+=10;carry=1;}
        else
        carry=0;
        res.pb(diff+'0');
    }
    if(cc)
    res.pb('-');
    reverse(res.begin(),res.end());
    return res;
}
                                                                //Addition
string operator+(string s1,string s2)
{
    if(s1.size()>s2.size())
    swap(s1,s2);
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    string res;
    ll n1=s1.size(),n2=s2.size(),carry=0,sum=0;
    for(ll i=0;i<n1;i++)
    {
        sum = (s1[i]-'0')+(s2[i]-'0')+carry;
        res.pb(sum%10+'0');
        carry = sum/10;
    }
    for(ll i=n1;i<n2;i++)
    {
        sum = (s2[i]-'0')+carry;
        res.pb(sum%10+'0');
        carry = sum/10;
    }
    if(carry)
    res.pb(carry+'0');
    reverse(res.begin(),res.end());
    return res;   
}
