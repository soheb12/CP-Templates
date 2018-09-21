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
                                                            //Multiplication
string operator*(string num1, string num2) 
{ 
    ll n1 = num1.size(); 
    ll n2 = num2.size(); 
    if (n1 == 0 || n2 == 0) 
       return "0"; 
    vector<ll> result(n1 + n2, 0); 
    ll i_n1 = 0;  
    ll i_n2 = 0;  
    for (ll i=n1-1; i>=0; i--) 
    { 
        ll carry = 0; 
        ll n1 = num1[i] - '0'; 
        i_n2 = 0;        
        for (ll j=n2-1; j>=0; j--) 
        { 
            ll n2 = num2[j] - '0'; 
            ll sum = n1*n2 + result[i_n1 + i_n2] + carry; 
            carry = sum/10; 
            result[i_n1 + i_n2] = sum % 10; 
            i_n2++; 
        } 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
        i_n1++; 
    } 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
       i--; 
    if (i == -1) 
       return "0"; 
    string s = ""; 
    while (i >= 0) 
        s += std::to_string(result[i--]); 
    return s; 
} 
                                                                //Division
string operator/(string num,ll div)
{
    string res;
    ll idx=0;
    ll temp = num[idx] - '0';
    while(temp < div)
    temp = temp*10 + (num[++idx]-'0');
    while(idx < num.size())
    {
        res += (temp/div)+'0';
        temp = (temp%div)*10 + num[++idx]-'0';
    }
    if(res.length() == 0)
    return "0";
    return res;
}


