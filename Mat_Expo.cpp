struct mat
{
    ll a[2][2];
};


mat matmul(mat x,mat y)
{
    mat ans;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            ans.a[i][j] = 0;
            for(int k=0;k<2;k++)
            {
                ans.a[i][j] = (ans.a[i][j] + x.a[i][k] * y.a[k][j])%mod;
            }
            
        }
    }
    return ans;
}

mat power(mat z,ll n)
{
    mat res;
    res.a[0][0] = 1;
    res.a[0][1] = 0;
    res.a[1][0] = 0;
    res.a[1][1] = 1;

    while(n>0)
    {
        if(n&1)
        res = matmul(res,z);

        n = n>>1;
        z = matmul(z,z);
    }
    return res;

}

// Solved this problem : https://www.codechef.com/problems/CKISSHUG
// Solved this problem : http://codeforces.com/contest/185/problem/A
