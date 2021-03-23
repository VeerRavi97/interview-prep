#include<bits/stdc++.h>
using namespace std;
int nthpowerofx(int x,int n){
   if(n==0) return 1;
   int temp=nthpowerofx(x,n/2); 
   if(n%2==0) return temp*temp;
   else
   {
       return x*temp*temp;
   }
   

}

int main(){
  
 int x,n;
 while(cin >> x >> n,n>0){
    
     int product=1;
     for(int i=1;i<=n;i++){  // O(N)
         product*=x;
     }
     cout << product  << " ";
     product=(long long)(pow((double)x,(double)n)+.5);
     cout << product  << " ";
     product=nthpowerofx(x,n);
      cout << product  << " ";
    cout << "\n";


   



 }





}