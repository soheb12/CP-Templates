#define ll long long
#define pb push_back

string operator+(string s1,string s2)
{
    if(n1>n2)
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
