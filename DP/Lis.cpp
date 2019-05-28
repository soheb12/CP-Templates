vector< ll >a(size); 
ll n;

//LONGEST NON DECREASING SUBSEQUENCE

ll ceilindex(vector< ll >tail , ll l,ll r,ll key)
{
    while(r-l > 1)
    {
        ll m = (l+r)/2;
        if(tail[m] >= key)//tail[m] > key
        r = m;
        else
        l = m;
    }
    return r;
}

ll lnds()//longest non decreasing subsequence
{
    if(a.size() == 0)return 0;
    vector< ll >tail(n,0);
    ll len = 1;
    tail[0] = a[0];
    f(1,n)
    {
        if(a[i] < tail[0])//a[i] < tail[0]
        tail[0] = a[i];
        else if(a[i] >= tail[len-1])//a[i] > tail[len-1]
        tail[len++] = a[i];
        else
        {
            ll ind = ceilindex(tail,-1,len-1,a[i]);//Alternatively LOWER_BOUND can be used
            if(tail[ind] == a[i])
            tail[++ind] = a[i];
            else
            tail[ind] = a[i];
            len = max(len,ind+1); 
        }
    }   
    return len;
}


//LONGEST INCREASING SUBSEQUENCE 

ll ceilindex(vector< ll >tail , ll l,ll r,ll key)
{
    while(r-l > 1)
    {
        ll m = (l+r)/2;
        if(tail[m] > key)//tail[m] > key
        r = m;
        else
        l = m;
    }
    return r;
}

ll lis()//longest increasing subsequence 
{
    if(a.size() == 0)return 0;
    vector< ll >tail(n,0);
    ll len = 1;
    tail[0] = a[0];
    f(1,n)
    {
        if(a[i] < tail[0])//a[i] < tail[0]
        tail[0] = a[i];
        else if(a[i] > tail[len-1])//a[i] > tail[len-1]
        tail[len++] = a[i];
        else
        {
            ll ind = ceilindex(tail,-1,len-1,a[i]);//Alternatively UPPER_BOUND can be used
            tail[ind] = a[i];
        }
    }   
    return len;
}
