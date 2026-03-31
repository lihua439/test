/*著名的王牌间谍 007 需要执行一次任务，获取敌方的机密情报。已知情报藏在一个地下迷宫里，迷宫只有一个入口，里面有很多条通路，每条路通向一扇门。每一扇门背后或者是一个房间，或者又有很多条路，同样是每条路通向一扇门…… 他的手里有一张表格，是其他间谍帮他收集到的情报，他们记下了每扇门的编号，以及这扇门背后的每一条通路所到达的门的编号。007 发现不存在两条路通向同一扇门。

内线告诉他，情报就藏在迷宫的最深处。但是这个迷宫太大了，他需要你的帮助 —— 请编程帮他找出距离入口最远的那扇门。*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<vector<int>>adj(n+1);
  vector<int>dist(n+1,-1);
  for(int i = 1; i <= n; i++)
    {
      int k;
      cin>>k;
      for(int j = 0; j < k; j++)
        {
          int h;
          cin>>h;
          adj[i].push_back(h);
          adj[h].push_back(i);
        }
    }
  queue<int>q;
  q.push(1);
  dist[1] = 0;
  while(!q.empty())
    {
      int v = q.front();
      q.pop();
      for(auto &i:adj[v])
        {
          if(dist[i] == -1)
          {
            dist[i] = dist[v]+1;
            q.push(i);
          }
        }
    }
  int max = 0;
  int maxpos = 1;
  for( int i = 1; i <= n; i++)
    {
      if(dist[i] > max)
      {
        maxpos = i;
        max = dist[i];
      }
    }
  cout<<maxpos<<endl;
  return 0;
}
