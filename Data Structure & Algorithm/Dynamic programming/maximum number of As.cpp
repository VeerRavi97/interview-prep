#include<bits/stdc++.h>
using namespace std;

const int MAX_N=75;

vector<int>memo(MAX_N,0);

int solve(int n){
  if(n<=6) return n;
  if(memo[n]) return memo[n];
  int ans=-1;
  for(int k=n-3;k>=1;k--){
      int cal=(n-k-1)*solve(k);
    ans=max(ans,cal);

  }
 memo[n]=ans;
 return ans;

}

 
int main(){
 int tc;
 cin >> tc;
 while(tc--){
 int n;
 cin >> n;
 int ans=solve(n);
 cout << ans << "\n";
  
  
 }
 
return 0;
}