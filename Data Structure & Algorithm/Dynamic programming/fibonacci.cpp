#include<bits/stdc++.h>
using namespace std;
int N=10000;
vector<int>v(N+1,-1);
vector<int>v1(N+1,-1);
// int fibrecurse(int n){  // Recursion
//  if(n==0) return 0;
//  if(n==1) return 1;
//  return fibrecurse(n-1)+fibrecurse(n-2);

// }
int fibmemo(int n){ // memoization
 // base case
   if(n<=1) return n;
   if(v[n]!=-1) return v[n];
   //recursive
   int ans=fibmemo(n-1)+fibmemo(n-2);
   // memoize
   v[n]=ans;
   return ans;
}

int fibdp(int n){
  v1[0]=0;
  v1[1]=1;
  for(int i=2;i<=n;i++){
      v1[i]=v1[i-1]+v1[i-2];
  }
 return v1[n];
}

int fibdpoptimized(int n){
  int a=0;
  int b=1;
  int c=0;
  for(int i=2;i<=n;i++){
      c=a+b;
       a=b;
      b=c;
     
  }
 return c;
}
int fib(int n) { 
  double phi = (1 + sqrt(5)) / 2; 
  return round(pow(phi, n) / sqrt(5)); 
} 

int main(){
  
  
  for(int n=0;n<100;n++){
   cout <<  fibmemo(n) << " " << fibdp(n) <<  " " <<  fibdpoptimized(n) << " " << fib(n) << "\n";
  }


    
}