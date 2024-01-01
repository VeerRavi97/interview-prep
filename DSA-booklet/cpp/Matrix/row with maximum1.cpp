#include<bits/stdc++.h>
using namespace std;
  void solve(vector<vector<int>>&v){
      int ans=-1,cnt=0;
   for(int row=0;row<v.size();row++){
    int x=-1;
    
    for(int b=v[row].size();b>=1;b/=2){
        while(x+b<v[row].size()&&!v[row][x+b])x+=b;
    }
    int index=x+1;
    
    if(cnt<(v[row].size()-index)){
          ans=row;
          cnt=v[row].size()-index;
          //  cout << ans << " " << cnt << "\n";
    }

   }

   
   cout << ans << " " << cnt << "\n";



  }



int main(){

vector<vector<int>>v={ {0, 0, 0, 1},  
                    {0, 1, 1, 1},  
                    {0, 0, 0, 1},  
                    {0, 0,1, 1}};


solve(v);


   return 0; 
}