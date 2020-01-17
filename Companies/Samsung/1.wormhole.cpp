#include<iostream>
using namespace std;
int n,sx,sy,dx,dy;
int w[11][5];
// int visited[11]; 
int ans;
int abs(int x){
    if(x<0)return -x;
    return x;
}
int min(int a,int b){
    if(a<b) return a;
    return b;
}
int dist(int x1,int y1,int x2,int y2){
    int dx=abs(x1-x2);
    int dy=abs(y1-y2);
    return dx+dy;
}
void solve(int sx,int sy,int val,int mask){
    //  cout << "step 2" << "\n";
    ans=min(ans,dist(sx,sy,dx,dy)+val);
    
   for(int i=0;i<n;i++){
       if(!(mask&(1<<i))){
           int temp1=val+dist(sx,sy,w[i][0],w[i][1])+w[i][4];
           int temp2=val+dist(sx,sy,w[i][2],w[i][3])+w[i][4];
           if(temp1<temp2)
           solve(w[i][2],w[i][3],temp1,mask|(1<<i));
           else
           solve(w[i][0],w[i][1],temp2,mask|(1<<i));
          
       }
   } 
    
    
}
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n;
        cin >> sx >> sy>>dx>>dy;
        for(int i=0;i<n;i++){
            cin >> w[i][0] >> w[i][1] >> w[i][2] >> w[i][3] >> w[i][4];
    //   visited[i]=0;
        }
        ans=99999;
        // cout << "step 1" << "\n";
        int mask=0;
        solve(sx,sy,0,0);
        cout << ans << "\n";
        
        
        
    }
    
    return 0;
}