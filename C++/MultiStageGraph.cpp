#include <bits/stdc++.h>
using namespace std;
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n = 8;
int mini,stages = 4;
int  cost[9],d[9],path[9];
int c[9][9] =
      {{0, 0, 0, 0, 0, 0, 0, 0,0},
       {0, 0, 2, 1, 3, 0, 0, 0,0},
       {0, 0, 0, 0, 0, 2, 3, 0,0},
       {0, 0, 0, 0, 0, 6, 7, 0,0},
       {0, 0, 0, 0, 0, 6, 8, 9,0},
       {0, 0, 0, 0, 0, 0, 0, 0,6},
       {0, 0, 0, 0, 0, 0, 0, 0,4},
      {0, 0, 0, 0, 0, 0, 0, 0,5},
      {0, 0, 0, 0, 0, 0, 0, 0,0}};

 cost[n]=0;
 for(int i = n-1;i>=1;i--){
     mini = INT_MAX;
     for (int k = i+1; k<=n; k++)
     {
         if (c[i][k] != 0 && c[i][k]+cost[k] < mini)
        {
        mini = (c[i][k]+cost[k]);
        d[i] = k;
        }
     }
     cost[i] = mini; 

 }
 path[1] = 1 ;
 path[stages]= n;
 for (int i = 2; i < stages; i++)
 {
     path[i]= d[path[i-1]];
 }

 cout<<cost[1]<<"\n";

 for (int i = 1; i <=stages; i++)
 {
     cout<<path[i]<<" ";
 }
 
return 0;
}