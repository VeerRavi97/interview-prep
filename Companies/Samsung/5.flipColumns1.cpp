#include<iostream>

using namespace std;

#define lim 20
int mat[lim][lim];
int n,m,ans;
void flip(int col){
    for(int i=0;i<n;i++)
    mat[i][col]=!mat[i][col];
}
int calculate(){
    int total=0;
    for(int i=0;i<n;i++){
        bool flag=true;
        for(int j=0;j<m;j++){
            if(!mat[i][j]){
            flag=false;
            break;
            }
        }
        if(flag) total++;
    }
    return total;
}
void solve(int k){
    if(k==0){
        int temp=calculate();
        ans=max(ans,temp);
        return;
    }

  for(int j=0;j<m;j++){
      flip(j);
      solve(k-1);
      flip(j);
  }
}

int main(){
    int k;
 cin >> n >> m >> k;

 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++) cin >> mat[i][j];
 }
 ans=-999999;
  solve(k);

 cout << ans << "\n"; 
 return 0;
}


/*

3 3 2
1 0 0
1 0 1
1 0 0


2

*/