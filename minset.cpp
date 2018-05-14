#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include<bits/stdc++.h>
using namespace std;

void minimumset( vector<pair<int,int>> arr, int t)
{
  sort(arr.begin(), arr.end(), [](auto &left, auto &right){
  return left.second < right.second || (left.second == right.second && left.first>right.first);});
  int pos1, pos2;
  pos1 = pos2 = -10; // Some arbitrary initilisation so that there is no junk that affects the program as such
  int count =  0;
    
  for(int i =0; i<t; i++)
  {
      if(arr[i].first > pos2)
      {
          pos2 = arr[i].second;
          pos1 = pos2 - 1;
          // There is disjointedness --- 
          count+=2; // Include both the elements of interest
      }
      else
      {
          if(arr[i].first>pos1)   // If the first element of interval is less than the other one... dont do anything -- already covered - else this branch... 
          {
          count+=1;
          pos1 = pos2;
          pos2 = arr[i].second;
          }
      }
  }
  printf("%d",count);
 
}


int main()
  
{
  vector<int> temp;
  vector<pair<int,int>> arr;
  int t;
  scanf("%d",&t);
  int a,b;
  for (int i=0; i<t;i++)
  {
      cin>>a>>b;
      arr.push_back(make_pair(a,b));
  }
  minimumset(arr, t);
  return 0;
}

