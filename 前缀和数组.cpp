#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e7;
typedef long long ll;
ll a[MAX],s1[MAX],s2[MAX];
inline ll calc(int l, int r)
{
  return s2[r] - s2[l-1] - (l*(s1[r]-s1[l-1]));
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while(t--)
    {
      int n,q;
      cin>>n>>q;
      for(int i = 1; i <= n; i++)
        {
          cin>>a[i];
        }
      s1[0] = 0,s2[0] = 0;
      for(int i = 1; i <= n; i++)
        {
          s1[i] = s1[i-1] + a[i];
          s2[i] = s2[i-1] + 1LL*a[i]*(i+1);
        }
      while(q--)
        {
          ll l,k;
          cin>>l>>k;
          if(a[l] > k) {
            cout<<-1<<endl;
            continue;
          }
          int left = l, right = n;
          int mid,ans=l;
          while(left <= right)
            {
              mid = (left + right)/2;
              if(calc(l,mid)<=k)
              {
                ans = mid;
                left = mid + 1;
              }
              else right = mid -1;
            }
          cout<<ans<<endl;
        }
    }
  return 0;
}
