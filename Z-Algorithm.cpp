void z_function()
{
    ll L=0,R=0;
    for(ll i=1;i<n;i++)
    {
        if(R < i)//Create A New Z Box
        {
            L = R = i;
            while(R < n && s[R-L] == s[R])
            R++;
            z[i] = R-L;
            R--;
        }
        else
        {
            ll k = i - L;
            if(z[k] < R - i + 1)//Inside Current Z Box
            z[i] = z[k];
            else//New Z Box
            {
                L = i;
                while(R < n && s[R-L] == s[R])
                R++;
                z[i] = R-L;
                R--;
            }
        }
    }
}
//Solved this problem : http://codeforces.com/contest/126/problem/B
//Solved this problem : https://www.codechef.com/problems/SECPASS lmao_
