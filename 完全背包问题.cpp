给定 1,2^2,3^2,⋯,17^2，以及一个正整数 n ，输出用给定的数组成 n 的不同方案数
输入格式:
输入有 T 组，第一行给出 T(1≤T≤10)
对于每一组数据，给出 n(1≤n≤300)
输出格式:
输出构成 n 的方案数
#include<bits/stdc++.h>
using namespace std;
#define vdebug(x) cout<<#x<<"="; for(auto &i : x) cout<<i<<" ";cout<<endl
int main()
{
    int t;
    cin>>t;
    while(t--)
        {
            int arr[18];
            for(int i = 1; i < 18; i++)
                {
                    arr[i] = i*i;
                }
            int dp[301] = {};
            dp[0] = 1;
            for(int j = 1; j < 18; j++)
                {
                        for(int i = 0; i <= 300; i++)
                    {
                        if(i>=arr[j])dp[i] += dp[i - arr[j]];
                        else continue;
                    }
                }
            //vdebug(dp);
            int n;
            cin>>n;
            cout<<dp[n]<<endl;
        }
    return 0;
}
