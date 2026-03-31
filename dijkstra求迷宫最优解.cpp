/*机器人必须在矩形区域周围巡逻, 矩阵大小为m×n网格（m行和n列）

行编号为从1到m。列编号为从1到n。

单元格（i，j）表示网格中第i行和第j列中的单元格。

在每一步中，机器人只能从一个单元移动到相邻单元，

即从（x，y）到（x+1，y），（x，y+1），（x-1，y）或（x，y-1）。

一些单元格包含障碍。为了移动到一个有障碍物的单元格，机器人必须切换到涡轮模式。

同时，机器人不能连续移动到含有障碍物的单元格k个以上。

您的任务是编写一个程序，从单元格（1，1）到单元格（m，n）中查找最短路径（单元格数最少）

假设这两个单元都不包含障碍物。*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e9;
typedef pair<int,pair<int,pair<int,int>>> p;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
int main()
{
  int t;
  cin>>t;
  while(t--)
    {
      int m,n,k;
      cin>>m>>n>>k;
      vector<vector<int>>grid(m,vector<int>(n));
      vector<vector<vector<int>>> dist(m,vector<vector<int>>(n,vector<int>(k+1,MAX)));
      for(int i = 0; i < m; i++)
        {
          for(int j = 0; j < n; j++)
            {
              cin>>grid[i][j];
            }
        }
      priority_queue<p,vector<p>,greater<p>>pq;
      pq.push({0,{0,{0,0}}});
      dist[0][0][0] = 0;
      bool check = true;
      while(!pq.empty())
        {
          auto now = pq.top();
          pq.pop();
          int d = now.first, kc = now.second.first, x = now.second.second.first, y = now.second.second.second;
          if( x == m-1 && y == n-1 ) 
          {
            cout<<d<<endl;
            check = false;
            break;
          }
          for(int i = 0; i < 4; i++)
            {
              int nx = x + dx[i];
              int ny = y + dy[i];
              if(nx < 0 || ny < 0 || nx > m-1 || ny > n-1) continue;
              int nkc = grid[nx][ny] ? kc+1 : 0;
              if(nkc > k) continue;
              if(dist[nx][ny][nkc] > d + 1)
              {
                dist[nx][ny][nkc] = d+1;
                pq.push({d+1,{nkc,{nx,ny}}});
              }
            }
        }
      if(check)
      {
        cout<<-1<<endl;
      }
    }
  return 0;
}

