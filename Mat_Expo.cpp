struct mat
{
    ll m[2][2];
};


mat matmul(mat x,mat y)
{
    mat ans;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            ans.m[i][j] = 0;
            for(int k=0;k<2;k++)
            {
                ans.m[i][j] = (ans.m[i][j] + x.m[i][k] * y.m[k][j])%mod;
            }
            
        }
    }
    return ans;
}

mat power(mat z,ll n)
{
    mat res;
    res.m[0][0] = 1;
    res.m[0][1] = 0;
    res.m[1][0] = 0;
    res.m[1][1] = 1;

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
// Solved this problem : https://codeforces.com/problemset/problem/166/E
