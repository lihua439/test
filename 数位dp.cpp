#include<bits/stdc++.h>
using namespace std;
int dp[20][20][20][2][2];
int x,y;
vector<int>digit;
typedef long long ll;
ll dfs(int pos,int cx,int cy,bool zero,bool tight)
{
    if(pos==digit.size())
    {
      return zero? 0 :cx > cy;
    }
  if(dp[pos][cx][cy][zero][tight]!=-1)
  {
    return dp[pos][cx][cy][zero][tight];
  }
  long long res=0;
  int upbound = tight? digit[pos] : 9;
  for(int d = 0; d <= upbound; d++)
    {
      bool new_zero = zero && d == 0;
      bool new_tight = tight && d == upbound;
      int new_cx,new_cy;
      if(!new_zero){
         new_cx = d == x? cx + 1: cx;
         new_cy = d == y? cy + 1: cy;
      }
      res += dfs(pos + 1,new_cx, new_cy,new_zero,new_tight);
    }
  return dp[pos][cx][cy][zero][tight] = res;
}

ll calc(ll n)
{
  digit.clear();
  memset(dp,-1,sizeof(dp));
  while(n>0)
    {
      digit.push_back(n%10);
      n/=10;
    }
  digit.reverse(digit.begin(),digit.end());
  return dfs(0,0,0,true,true);
}
int main(){
  int t;
  cin>>t;
  ios::sync_with_stdio(false); cin.tie(0);
  while(t--)
    {
      long long l,m;
      cin>>x>>y>>l>>m;
      cout<<calc(m)-calc(l-1)<<endl;
    }
  return 0;
}
