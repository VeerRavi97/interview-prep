#include<bits/stdc++.h>
using namespace std;
const int N=8;
bool issafe(int board[N][N],int i,int j){
  
  for(int k=0;k<=i;k++){
      
      if(board[k][j]==1) 
      {
          return false;
      }
  }
  int x=i;
  int y=j;
  while(x>=0&&y>=0){
      if(board[x][y]==1) return false;
      x--;
      y--;
  }
  x=i;
  y=j;
  while(x>=0&&y<N){
      if(board[x][y]==1) return false;
      x--;
      y++;
  }
return true;

}
 bool solve(int board[N][N],int i){
 // Base case
    if(i==N){
       for(int i=0;i<N;i++){
       for(int j=0;j<N;j++) {
           cout << board[i][j] << " ";
       }
       cout << "\n";
    }
    cout << "\n\n";
        return true;
    }

 // Recursive case
 for(int j=0;j<N;j++){
   if(issafe(board,i,j)){
      board[i][j]=1;
      bool flag= solve(board,i+1);
    
    //   if(flag) return true;
      board[i][j]=0;
   }

 }
return false;


}
int main(){

int board[N][N];
memset(board,0,sizeof(board));
solve(board,0);

}
