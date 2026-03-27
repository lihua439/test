#include<bits/stdc++.h>
using namespace std;
struct haffuman{
  int lchild;
  int rchild;
  int parent;
  int weight;
  huffman(int w){
    lchild = 0;
    rchile = 0;
    parent = 0;
    weight = w;
  }
}
typedef haffuman* HaffumanTree;
typedef char** HuffumanCode;
void SelectTwoMin(int &x,int &y,int upbound, HaffumanTree &HT)
{
  int x=0,y=0;
  int min1 = 1000,min2 = 1000;
  for(int i = 1; i <= upbound; i++)
    {
      if(HT[i].parent==0)
      {
        if(HT[i].weight<min1)
        {
          y = x;
          min2 = min1;
          x = i;
          min1 = HT[i].weight;
        }
        else if(HT[i].weight < min2)
        {
          min2 = HT[i].weight;
          y = i;
        }
      }
    }
  if(x>y)
  {
    int tmp = x;
    x = y;
    y = tmp;
  }
}
}
void HaffumanCoding(HaffumanTree &HT,HuffumanCode &HC,int n,int* w)
{
  int m = 2 * n -1;
  HT=new haffuman[n+1];
  for(int i=1;i<=m;i++)
    {
      HT[i].lchild = 0;
      HT[i].rchild = 0;
      HT[i].parent = 0;
    }
  for(int i = 1;i <= n;i++)
    {
      HT[i].weight = w[i-1];
    }
  for(int i = n+1; i <= m; i++)
    {
      
}
